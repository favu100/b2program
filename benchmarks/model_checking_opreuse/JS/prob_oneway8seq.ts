import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BRelation} from './btypes/BRelation.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {PreconditionOrAssertionViolation} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";




class _ProjectionRead_move0 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move0 = this;
        let o2: _ProjectionRead_move0 = other as _ProjectionRead_move0;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move0 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move0 = this;
        let o2: _ProjectionRead__tr_move0 = other as _ProjectionRead__tr_move0;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move0 {

    public P0: BInteger;
    public RB: BInteger;
    public RA: BInteger;

    constructor(P0 : BInteger, RB : BInteger, RA : BInteger) {
        this.P0 = P0;
        this.RB = RB;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move0 = this;
        let o2: _ProjectionWrite_move0 = other as _ProjectionWrite_move0;
        return o1.P0.equals(o2.P0) && o1.RB.equals(o2.RB) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_move1 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move1 = this;
        let o2: _ProjectionRead_move1 = other as _ProjectionRead_move1;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move1 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move1 = this;
        let o2: _ProjectionRead__tr_move1 = other as _ProjectionRead__tr_move1;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move1 {

    public RB: BInteger;
    public P1: BInteger;
    public RA: BInteger;

    constructor(RB : BInteger, P1 : BInteger, RA : BInteger) {
        this.RB = RB;
        this.P1 = P1;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move1 = this;
        let o2: _ProjectionWrite_move1 = other as _ProjectionWrite_move1;
        return o1.RB.equals(o2.RB) && o1.P1.equals(o2.P1) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_move2 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move2 = this;
        let o2: _ProjectionRead_move2 = other as _ProjectionRead_move2;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move2 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move2 = this;
        let o2: _ProjectionRead__tr_move2 = other as _ProjectionRead__tr_move2;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move2 {

    public RB: BInteger;
    public P2: BInteger;
    public RA: BInteger;

    constructor(RB : BInteger, P2 : BInteger, RA : BInteger) {
        this.RB = RB;
        this.P2 = P2;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move2 = this;
        let o2: _ProjectionWrite_move2 = other as _ProjectionWrite_move2;
        return o1.RB.equals(o2.RB) && o1.P2.equals(o2.P2) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_move3 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move3 = this;
        let o2: _ProjectionRead_move3 = other as _ProjectionRead_move3;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move3 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move3 = this;
        let o2: _ProjectionRead__tr_move3 = other as _ProjectionRead__tr_move3;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move3 {

    public RB: BInteger;
    public P3: BInteger;
    public RA: BInteger;

    constructor(RB : BInteger, P3 : BInteger, RA : BInteger) {
        this.RB = RB;
        this.P3 = P3;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move3 = this;
        let o2: _ProjectionWrite_move3 = other as _ProjectionWrite_move3;
        return o1.RB.equals(o2.RB) && o1.P3.equals(o2.P3) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_move4 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move4 = this;
        let o2: _ProjectionRead_move4 = other as _ProjectionRead_move4;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move4 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move4 = this;
        let o2: _ProjectionRead__tr_move4 = other as _ProjectionRead__tr_move4;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move4 {

    public RB: BInteger;
    public P4: BInteger;
    public RA: BInteger;

    constructor(RB : BInteger, P4 : BInteger, RA : BInteger) {
        this.RB = RB;
        this.P4 = P4;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move4 = this;
        let o2: _ProjectionWrite_move4 = other as _ProjectionWrite_move4;
        return o1.RB.equals(o2.RB) && o1.P4.equals(o2.P4) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_move5 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move5 = this;
        let o2: _ProjectionRead_move5 = other as _ProjectionRead_move5;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move5 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move5 = this;
        let o2: _ProjectionRead__tr_move5 = other as _ProjectionRead__tr_move5;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move5 {

    public RB: BInteger;
    public P5: BInteger;
    public RA: BInteger;

    constructor(RB : BInteger, P5 : BInteger, RA : BInteger) {
        this.RB = RB;
        this.P5 = P5;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move5 = this;
        let o2: _ProjectionWrite_move5 = other as _ProjectionWrite_move5;
        return o1.RB.equals(o2.RB) && o1.P5.equals(o2.P5) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_move6 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move6 = this;
        let o2: _ProjectionRead_move6 = other as _ProjectionRead_move6;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move6 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move6 = this;
        let o2: _ProjectionRead__tr_move6 = other as _ProjectionRead__tr_move6;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move6 {

    public RB: BInteger;
    public P6: BInteger;
    public RA: BInteger;

    constructor(RB : BInteger, P6 : BInteger, RA : BInteger) {
        this.RB = RB;
        this.P6 = P6;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move6 = this;
        let o2: _ProjectionWrite_move6 = other as _ProjectionWrite_move6;
        return o1.RB.equals(o2.RB) && o1.P6.equals(o2.P6) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_move7 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_move7 = this;
        let o2: _ProjectionRead_move7 = other as _ProjectionRead_move7;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_move7 {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;
    public RA: BInteger;
    public RB: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger, RA : BInteger, RB : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
        this.RA = RA;
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_move7 = this;
        let o2: _ProjectionRead__tr_move7 = other as _ProjectionRead__tr_move7;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA) && o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_move7 {

    public RB: BInteger;
    public P7: BInteger;
    public RA: BInteger;

    constructor(RB : BInteger, P7 : BInteger, RA : BInteger) {
        this.RB = RB;
        this.P7 = P7;
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_move7 = this;
        let o2: _ProjectionWrite_move7 = other as _ProjectionWrite_move7;
        return o1.RB.equals(o2.RB) && o1.P7.equals(o2.P7) && o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_arrived {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_arrived = this;
        let o2: _ProjectionRead_arrived = other as _ProjectionRead_arrived;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_arrived {

    public P0: BInteger;
    public P1: BInteger;
    public P2: BInteger;
    public P3: BInteger;
    public P4: BInteger;
    public P5: BInteger;
    public P6: BInteger;
    public P7: BInteger;

    constructor(P0 : BInteger, P1 : BInteger, P2 : BInteger, P3 : BInteger, P4 : BInteger, P5 : BInteger, P6 : BInteger, P7 : BInteger) {
        this.P0 = P0;
        this.P1 = P1;
        this.P2 = P2;
        this.P3 = P3;
        this.P4 = P4;
        this.P5 = P5;
        this.P6 = P6;
        this.P7 = P7;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_arrived = this;
        let o2: _ProjectionRead__tr_arrived = other as _ProjectionRead__tr_arrived;
        return o1.P0.equals(o2.P0) && o1.P1.equals(o2.P1) && o1.P2.equals(o2.P2) && o1.P3.equals(o2.P3) && o1.P4.equals(o2.P4) && o1.P5.equals(o2.P5) && o1.P6.equals(o2.P6) && o1.P7.equals(o2.P7);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        result = 31 * result + (this.P1.hashCode() << 1);
        result = 31 * result + (this.P2.hashCode() << 1);
        result = 31 * result + (this.P3.hashCode() << 1);
        result = 31 * result + (this.P4.hashCode() << 1);
        result = 31 * result + (this.P5.hashCode() << 1);
        result = 31 * result + (this.P6.hashCode() << 1);
        result = 31 * result + (this.P7.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_arrived {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_arrived = this;
        let o2: _ProjectionWrite_arrived = other as _ProjectionWrite_arrived;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public P0: BInteger;

    constructor(P0 : BInteger) {
        this.P0 = P0;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.P0.equals(o2.P0);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P0.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public P1: BInteger;

    constructor(P1 : BInteger) {
        this.P1 = P1;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.P1.equals(o2.P1);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P1.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public P2: BInteger;

    constructor(P2 : BInteger) {
        this.P2 = P2;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.P2.equals(o2.P2);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P2.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public P3: BInteger;

    constructor(P3 : BInteger) {
        this.P3 = P3;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.P3.equals(o2.P3);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P3.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public P4: BInteger;

    constructor(P4 : BInteger) {
        this.P4 = P4;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.P4.equals(o2.P4);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P4.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public P5: BInteger;

    constructor(P5 : BInteger) {
        this.P5 = P5;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.P5.equals(o2.P5);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P5.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public P6: BInteger;

    constructor(P6 : BInteger) {
        this.P6 = P6;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.P6.equals(o2.P6);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P6.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_8 {

    public P7: BInteger;

    constructor(P7 : BInteger) {
        this.P7 = P7;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_8 = this;
        let o2: _ProjectionRead__check_inv_8 = other as _ProjectionRead__check_inv_8;
        return o1.P7.equals(o2.P7);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.P7.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_9 {

    public RA: BInteger;

    constructor(RA : BInteger) {
        this.RA = RA;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_9 = this;
        let o2: _ProjectionRead__check_inv_9 = other as _ProjectionRead__check_inv_9;
        return o1.RA.equals(o2.RA);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RA.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_10 {

    public RB: BInteger;

    constructor(RB : BInteger) {
        this.RB = RB;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_10 = this;
        let o2: _ProjectionRead__check_inv_10 = other as _ProjectionRead__check_inv_10;
        return o1.RB.equals(o2.RB);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RB.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class prob_oneway8seq {

    parent: prob_oneway8seq;
    stateAccessedVia: string;


    private static T0: BRelation<BInteger, BInteger>;
    private static T1: BRelation<BInteger, BInteger>;
    private static T2: BRelation<BInteger, BInteger>;
    private static T3: BRelation<BInteger, BInteger>;
    private static T4: BRelation<BInteger, BInteger>;
    private static T5: BRelation<BInteger, BInteger>;
    private static T6: BRelation<BInteger, BInteger>;
    private static T7: BRelation<BInteger, BInteger>;
    private static A0: BRelation<BInteger, BInteger>;
    private static A1: BRelation<BInteger, BInteger>;
    private static A2: BRelation<BInteger, BInteger>;
    private static A3: BRelation<BInteger, BInteger>;
    private static A4: BRelation<BInteger, BInteger>;
    private static A5: BRelation<BInteger, BInteger>;
    private static A6: BRelation<BInteger, BInteger>;
    private static A7: BRelation<BInteger, BInteger>;
    private static B0: BRelation<BInteger, BInteger>;
    private static B1: BRelation<BInteger, BInteger>;
    private static B2: BRelation<BInteger, BInteger>;
    private static B3: BRelation<BInteger, BInteger>;
    private static B4: BRelation<BInteger, BInteger>;
    private static B5: BRelation<BInteger, BInteger>;
    private static B6: BRelation<BInteger, BInteger>;
    private static B7: BRelation<BInteger, BInteger>;
    private static LA: BInteger;
    private static LB: BInteger;


    private P0: BInteger;
    private P1: BInteger;
    private P2: BInteger;
    private P3: BInteger;
    private P4: BInteger;
    private P5: BInteger;
    private P6: BInteger;
    private P7: BInteger;
    private RA: BInteger;
    private RB: BInteger;

    static {
        prob_oneway8seq.T0 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(1)), new BTuple(new BInteger(1), new BInteger(9)), new BTuple(new BInteger(2), new BInteger(10)), new BTuple(new BInteger(3), new BInteger(13)), new BTuple(new BInteger(4), new BInteger(15)), new BTuple(new BInteger(5), new BInteger(20)), new BTuple(new BInteger(6), new BInteger(23)));
        prob_oneway8seq.T1 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(3)), new BTuple(new BInteger(1), new BInteger(9)), new BTuple(new BInteger(2), new BInteger(10)), new BTuple(new BInteger(3), new BInteger(13)), new BTuple(new BInteger(4), new BInteger(15)), new BTuple(new BInteger(5), new BInteger(20)), new BTuple(new BInteger(6), new BInteger(24)));
        prob_oneway8seq.T2 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(5)), new BTuple(new BInteger(1), new BInteger(27)), new BTuple(new BInteger(2), new BInteger(11)), new BTuple(new BInteger(3), new BInteger(13)), new BTuple(new BInteger(4), new BInteger(16)), new BTuple(new BInteger(5), new BInteger(20)), new BTuple(new BInteger(6), new BInteger(25)));
        prob_oneway8seq.T3 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(7)), new BTuple(new BInteger(1), new BInteger(27)), new BTuple(new BInteger(2), new BInteger(11)), new BTuple(new BInteger(3), new BInteger(13)), new BTuple(new BInteger(4), new BInteger(16)), new BTuple(new BInteger(5), new BInteger(20)), new BTuple(new BInteger(6), new BInteger(26)));
        prob_oneway8seq.T4 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(23)), new BTuple(new BInteger(1), new BInteger(22)), new BTuple(new BInteger(2), new BInteger(17)), new BTuple(new BInteger(3), new BInteger(18)), new BTuple(new BInteger(4), new BInteger(11)), new BTuple(new BInteger(5), new BInteger(9)), new BTuple(new BInteger(6), new BInteger(2)));
        prob_oneway8seq.T5 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(24)), new BTuple(new BInteger(1), new BInteger(22)), new BTuple(new BInteger(2), new BInteger(17)), new BTuple(new BInteger(3), new BInteger(18)), new BTuple(new BInteger(4), new BInteger(11)), new BTuple(new BInteger(5), new BInteger(9)), new BTuple(new BInteger(6), new BInteger(4)));
        prob_oneway8seq.T6 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(25)), new BTuple(new BInteger(1), new BInteger(22)), new BTuple(new BInteger(2), new BInteger(17)), new BTuple(new BInteger(3), new BInteger(18)), new BTuple(new BInteger(4), new BInteger(12)), new BTuple(new BInteger(5), new BInteger(27)), new BTuple(new BInteger(6), new BInteger(6)));
        prob_oneway8seq.T7 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(26)), new BTuple(new BInteger(1), new BInteger(22)), new BTuple(new BInteger(2), new BInteger(17)), new BTuple(new BInteger(3), new BInteger(18)), new BTuple(new BInteger(4), new BInteger(12)), new BTuple(new BInteger(5), new BInteger(27)), new BTuple(new BInteger(6), new BInteger(8)));
        prob_oneway8seq.A0 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1)), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(1).negative()), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.A1 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1)), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(1).negative()), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.A2 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(1)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(1)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.A3 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(1)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.A4 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(1)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(0)), new BTuple(new BInteger(4), new BInteger(1).negative()), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.A5 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(1)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(0)), new BTuple(new BInteger(4), new BInteger(1).negative()), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.A6 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.A7 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(1)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B0 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1)), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(1).negative()), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B1 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1)), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(1).negative()), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B2 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(1)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B3 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(1)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(1)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B4 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(1)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(0).negative()), new BTuple(new BInteger(4), new BInteger(1).negative()), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B5 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(1)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(0)), new BTuple(new BInteger(4), new BInteger(1).negative()), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B6 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(1)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.B7 = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)), new BTuple(new BInteger(1), new BInteger(0)), new BTuple(new BInteger(2), new BInteger(0)), new BTuple(new BInteger(3), new BInteger(1).negative()), new BTuple(new BInteger(4), new BInteger(0)), new BTuple(new BInteger(5), new BInteger(0)), new BTuple(new BInteger(6), new BInteger(0)));
        prob_oneway8seq.LA = new BInteger(7);
        prob_oneway8seq.LB = new BInteger(7);
        if(!(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(prob_oneway8seq.T0.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T0.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T0.isFunction()).and(prob_oneway8seq.T0.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue() && prob_oneway8seq.T1.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T1.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T1.isFunction()).and(prob_oneway8seq.T1.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.T2.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T2.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T2.isFunction()).and(prob_oneway8seq.T2.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.T3.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T3.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T3.isFunction()).and(prob_oneway8seq.T3.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.T4.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T4.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T4.isFunction()).and(prob_oneway8seq.T4.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.T5.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T5.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T5.isFunction()).and(prob_oneway8seq.T5.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.T6.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T6.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T6.isFunction()).and(prob_oneway8seq.T6.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.T7.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.T7.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(prob_oneway8seq.T7.isFunction()).and(prob_oneway8seq.T7.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A0.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A0.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A0.isFunction()).and(prob_oneway8seq.A0.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A1.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A1.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A1.isFunction()).and(prob_oneway8seq.A1.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A2.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A2.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A2.isFunction()).and(prob_oneway8seq.A2.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A3.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A3.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A3.isFunction()).and(prob_oneway8seq.A3.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A4.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A4.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A4.isFunction()).and(prob_oneway8seq.A4.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A5.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A5.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A5.isFunction()).and(prob_oneway8seq.A5.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A6.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A6.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A6.isFunction()).and(prob_oneway8seq.A6.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.A7.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.A7.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.A7.isFunction()).and(prob_oneway8seq.A7.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B0.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B0.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B0.isFunction()).and(prob_oneway8seq.B0.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B1.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B1.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B1.isFunction()).and(prob_oneway8seq.B1.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B2.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B2.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B2.isFunction()).and(prob_oneway8seq.B2.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B3.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B3.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B3.isFunction()).and(prob_oneway8seq.B3.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B4.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B4.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B4.isFunction()).and(prob_oneway8seq.B4.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B5.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B5.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B5.isFunction()).and(prob_oneway8seq.B5.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B6.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B6.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B6.isFunction()).and(prob_oneway8seq.B6.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.B7.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(prob_oneway8seq.B7.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(prob_oneway8seq.B7.isFunction()).and(prob_oneway8seq.B7.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(new BInteger(0)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(new BInteger(1)).equal(new BInteger(9)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(new BInteger(2)).equal(new BInteger(10)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(new BInteger(4)).equal(new BInteger(15)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(new BInteger(6)).equal(new BInteger(23)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(new BInteger(0)).equal(new BInteger(3)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(new BInteger(1)).equal(new BInteger(9)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(new BInteger(2)).equal(new BInteger(10)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(new BInteger(4)).equal(new BInteger(15)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(new BInteger(6)).equal(new BInteger(24)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(new BInteger(0)).equal(new BInteger(5)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(new BInteger(1)).equal(new BInteger(27)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(new BInteger(2)).equal(new BInteger(11)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(new BInteger(4)).equal(new BInteger(16)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(new BInteger(6)).equal(new BInteger(25)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(new BInteger(0)).equal(new BInteger(7)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(new BInteger(1)).equal(new BInteger(27)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(new BInteger(2)).equal(new BInteger(11)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(new BInteger(4)).equal(new BInteger(16)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(new BInteger(6)).equal(new BInteger(26)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(new BInteger(0)).equal(new BInteger(23)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(new BInteger(4)).equal(new BInteger(11)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(new BInteger(5)).equal(new BInteger(9)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(new BInteger(6)).equal(new BInteger(2)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(new BInteger(0)).equal(new BInteger(24)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(new BInteger(4)).equal(new BInteger(11)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(new BInteger(5)).equal(new BInteger(9)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(new BInteger(6)).equal(new BInteger(4)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(new BInteger(0)).equal(new BInteger(25)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(new BInteger(4)).equal(new BInteger(12)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(new BInteger(5)).equal(new BInteger(27)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(new BInteger(6)).equal(new BInteger(6)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(new BInteger(0)).equal(new BInteger(26)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(new BInteger(4)).equal(new BInteger(12)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(new BInteger(5)).equal(new BInteger(27)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(new BInteger(6)).equal(new BInteger(8)).booleanValue()).booleanValue() && prob_oneway8seq.A0.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A0.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A0.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A0.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A0.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A0.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A0.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A1.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A1.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A1.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A1.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A1.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A1.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A1.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A2.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A2.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A2.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A2.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A2.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A2.functionCall(new BInteger(5)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A2.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A3.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A3.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A3.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A3.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A3.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A3.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A3.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A4.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A4.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A4.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A4.functionCall(new BInteger(3)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A4.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A4.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A4.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A5.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A5.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A5.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A5.functionCall(new BInteger(3)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A5.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A5.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A5.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A6.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A6.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A6.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A6.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A6.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A6.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A6.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A7.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A7.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.A7.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A7.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.A7.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A7.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.A7.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B0.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B0.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B0.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B0.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B0.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B0.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B0.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B1.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B1.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B1.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B1.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B1.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B1.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B1.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B2.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B2.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B2.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B2.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B2.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B2.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B2.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B3.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B3.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B3.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B3.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B3.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B3.functionCall(new BInteger(5)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B3.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B4.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B4.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B4.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B4.functionCall(new BInteger(3)).equal(new BInteger(0).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B4.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B4.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B4.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B5.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B5.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B5.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B5.functionCall(new BInteger(3)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B5.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B5.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B5.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B6.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B6.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && prob_oneway8seq.B6.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B6.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B6.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B6.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B6.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B7.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B7.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B7.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B7.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && prob_oneway8seq.B7.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B7.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && prob_oneway8seq.B7.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue())).booleanValue()) {
            throw new Error("Contradiction in PROPERTIES detected!");
        }
    }

    constructor(copy? : prob_oneway8seq) {
        if(copy) {
            this.P0 = copy.P0;
            this.P1 = copy.P1;
            this.P2 = copy.P2;
            this.P3 = copy.P3;
            this.P4 = copy.P4;
            this.P5 = copy.P5;
            this.P6 = copy.P6;
            this.P7 = copy.P7;
            this.RA = copy.RA;
            this.RB = copy.RB;
        } else {
            this.P0 = new BInteger(0);
            this.P1 = new BInteger(0);
            this.P2 = new BInteger(0);
            this.P3 = new BInteger(0);
            this.P4 = new BInteger(0);
            this.P5 = new BInteger(0);
            this.P6 = new BInteger(0);
            this.P7 = new BInteger(0);
            this.RA = new BInteger(1);
            this.RB = new BInteger(1);
        }
    }



    move0(): void {
        this.P0 = this.P0.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A0.functionCall(this.P0));
        this.RB = this.RB.plus(prob_oneway8seq.B0.functionCall(this.P0));

    }

    move1(): void {
        this.P1 = this.P1.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A1.functionCall(this.P1));
        this.RB = this.RB.plus(prob_oneway8seq.B1.functionCall(this.P1));

    }

    move2(): void {
        this.P2 = this.P2.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A2.functionCall(this.P2));
        this.RB = this.RB.plus(prob_oneway8seq.B2.functionCall(this.P2));

    }

    move3(): void {
        this.P3 = this.P3.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A3.functionCall(this.P3));
        this.RB = this.RB.plus(prob_oneway8seq.B3.functionCall(this.P3));

    }

    move4(): void {
        this.P4 = this.P4.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A4.functionCall(this.P4));
        this.RB = this.RB.plus(prob_oneway8seq.B4.functionCall(this.P4));

    }

    move5(): void {
        this.P5 = this.P5.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A5.functionCall(this.P5));
        this.RB = this.RB.plus(prob_oneway8seq.B5.functionCall(this.P5));

    }

    move6(): void {
        this.P6 = this.P6.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A6.functionCall(this.P6));
        this.RB = this.RB.plus(prob_oneway8seq.B6.functionCall(this.P6));

    }

    move7(): void {
        this.P7 = this.P7.plus(new BInteger(1));
        this.RA = this.RA.plus(prob_oneway8seq.A7.functionCall(this.P7));
        this.RB = this.RB.plus(prob_oneway8seq.B7.functionCall(this.P7));

    }

    arrived(): void {
    }

    _get_T0(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T0;
    }

    _get_T1(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T1;
    }

    _get_T2(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T2;
    }

    _get_T3(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T3;
    }

    _get_T4(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T4;
    }

    _get_T5(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T5;
    }

    _get_T6(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T6;
    }

    _get_T7(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.T7;
    }

    _get_A0(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A0;
    }

    _get_A1(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A1;
    }

    _get_A2(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A2;
    }

    _get_A3(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A3;
    }

    _get_A4(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A4;
    }

    _get_A5(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A5;
    }

    _get_A6(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A6;
    }

    _get_A7(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.A7;
    }

    _get_B0(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B0;
    }

    _get_B1(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B1;
    }

    _get_B2(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B2;
    }

    _get_B3(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B3;
    }

    _get_B4(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B4;
    }

    _get_B5(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B5;
    }

    _get_B6(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B6;
    }

    _get_B7(): BRelation<BInteger, BInteger> {
        return prob_oneway8seq.B7;
    }

    _get_LA(): BInteger {
        return prob_oneway8seq.LA;
    }

    _get_LB(): BInteger {
        return prob_oneway8seq.LB;
    }

    _get_P0(): BInteger {
        return this.P0;
    }

    _get_P1(): BInteger {
        return this.P1;
    }

    _get_P2(): BInteger {
        return this.P2;
    }

    _get_P3(): BInteger {
        return this.P3;
    }

    _get_P4(): BInteger {
        return this.P4;
    }

    _get_P5(): BInteger {
        return this.P5;
    }

    _get_P6(): BInteger {
        return this.P6;
    }

    _get_P7(): BInteger {
        return this.P7;
    }

    _get_RA(): BInteger {
        return this.RA;
    }

    _get_RB(): BInteger {
        return this.RB;
    }

    equals(o: any): boolean {
        let o1: prob_oneway8seq = this;
        let o2: prob_oneway8seq = o as prob_oneway8seq;
        return o1._get_P0().equals(o2._get_P0()) && o1._get_P1().equals(o2._get_P1()) && o1._get_P2().equals(o2._get_P2()) && o1._get_P3().equals(o2._get_P3()) && o1._get_P4().equals(o2._get_P4()) && o1._get_P5().equals(o2._get_P5()) && o1._get_P6().equals(o2._get_P6()) && o1._get_P7().equals(o2._get_P7()) && o1._get_RA().equals(o2._get_RA()) && o1._get_RB().equals(o2._get_RB());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_P0()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P1()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P2()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P3()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P4()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P5()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P6()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P7()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_RA()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_RB()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_P0()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P1()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P2()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P3()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P4()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P5()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P6()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P7()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_RA()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_RB()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_P0: " + (this._get_P0()).toString(), "_get_P1: " + (this._get_P1()).toString(), "_get_P2: " + (this._get_P2()).toString(), "_get_P3: " + (this._get_P3()).toString(), "_get_P4: " + (this._get_P4()).toString(), "_get_P5: " + (this._get_P5()).toString(), "_get_P6: " + (this._get_P6()).toString(), "_get_P7: " + (this._get_P7()).toString(), "_get_RA: " + (this._get_RA()).toString(), "_get_RB: " + (this._get_RB()).toString());
    }
    */

    _tr_move0(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P0.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T0.functionCall(this.P0.plus(new BInteger(1))).unequal(prob_oneway8seq.T1.functionCall(this.P1)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(this.P0.plus(new BInteger(1))).unequal(prob_oneway8seq.T2.functionCall(this.P2)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(this.P0.plus(new BInteger(1))).unequal(prob_oneway8seq.T3.functionCall(this.P3)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(this.P0.plus(new BInteger(1))).unequal(prob_oneway8seq.T4.functionCall(this.P4)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(this.P0.plus(new BInteger(1))).unequal(prob_oneway8seq.T5.functionCall(this.P5)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(this.P0.plus(new BInteger(1))).unequal(prob_oneway8seq.T6.functionCall(this.P6)).booleanValue()).booleanValue() && prob_oneway8seq.T0.functionCall(this.P0.plus(new BInteger(1))).unequal(prob_oneway8seq.T7.functionCall(this.P7)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A0.functionCall(this.P0.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B0.functionCall(this.P0.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_move1(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P1.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T1.functionCall(this.P1.plus(new BInteger(1))).unequal(prob_oneway8seq.T0.functionCall(this.P0)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(this.P1.plus(new BInteger(1))).unequal(prob_oneway8seq.T2.functionCall(this.P2)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(this.P1.plus(new BInteger(1))).unequal(prob_oneway8seq.T3.functionCall(this.P3)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(this.P1.plus(new BInteger(1))).unequal(prob_oneway8seq.T4.functionCall(this.P4)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(this.P1.plus(new BInteger(1))).unequal(prob_oneway8seq.T5.functionCall(this.P5)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(this.P1.plus(new BInteger(1))).unequal(prob_oneway8seq.T6.functionCall(this.P6)).booleanValue()).booleanValue() && prob_oneway8seq.T1.functionCall(this.P1.plus(new BInteger(1))).unequal(prob_oneway8seq.T7.functionCall(this.P7)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A1.functionCall(this.P1.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B1.functionCall(this.P1.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_move2(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P2.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T2.functionCall(this.P2.plus(new BInteger(1))).unequal(prob_oneway8seq.T0.functionCall(this.P0)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(this.P2.plus(new BInteger(1))).unequal(prob_oneway8seq.T1.functionCall(this.P1)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(this.P2.plus(new BInteger(1))).unequal(prob_oneway8seq.T3.functionCall(this.P3)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(this.P2.plus(new BInteger(1))).unequal(prob_oneway8seq.T4.functionCall(this.P4)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(this.P2.plus(new BInteger(1))).unequal(prob_oneway8seq.T5.functionCall(this.P5)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(this.P2.plus(new BInteger(1))).unequal(prob_oneway8seq.T6.functionCall(this.P6)).booleanValue()).booleanValue() && prob_oneway8seq.T2.functionCall(this.P2.plus(new BInteger(1))).unequal(prob_oneway8seq.T7.functionCall(this.P7)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A2.functionCall(this.P2.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B2.functionCall(this.P2.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_move3(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P3.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T3.functionCall(this.P3.plus(new BInteger(1))).unequal(prob_oneway8seq.T0.functionCall(this.P0)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(this.P3.plus(new BInteger(1))).unequal(prob_oneway8seq.T1.functionCall(this.P1)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(this.P3.plus(new BInteger(1))).unequal(prob_oneway8seq.T2.functionCall(this.P2)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(this.P3.plus(new BInteger(1))).unequal(prob_oneway8seq.T4.functionCall(this.P4)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(this.P3.plus(new BInteger(1))).unequal(prob_oneway8seq.T5.functionCall(this.P5)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(this.P3.plus(new BInteger(1))).unequal(prob_oneway8seq.T6.functionCall(this.P6)).booleanValue()).booleanValue() && prob_oneway8seq.T3.functionCall(this.P3.plus(new BInteger(1))).unequal(prob_oneway8seq.T7.functionCall(this.P7)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A3.functionCall(this.P3.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B3.functionCall(this.P3.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_move4(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P4.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T4.functionCall(this.P4.plus(new BInteger(1))).unequal(prob_oneway8seq.T0.functionCall(this.P0)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(this.P4.plus(new BInteger(1))).unequal(prob_oneway8seq.T1.functionCall(this.P1)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(this.P4.plus(new BInteger(1))).unequal(prob_oneway8seq.T2.functionCall(this.P2)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(this.P4.plus(new BInteger(1))).unequal(prob_oneway8seq.T3.functionCall(this.P3)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(this.P4.plus(new BInteger(1))).unequal(prob_oneway8seq.T5.functionCall(this.P5)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(this.P4.plus(new BInteger(1))).unequal(prob_oneway8seq.T6.functionCall(this.P6)).booleanValue()).booleanValue() && prob_oneway8seq.T4.functionCall(this.P4.plus(new BInteger(1))).unequal(prob_oneway8seq.T7.functionCall(this.P7)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A4.functionCall(this.P4.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B4.functionCall(this.P4.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_move5(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P5.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T5.functionCall(this.P5.plus(new BInteger(1))).unequal(prob_oneway8seq.T0.functionCall(this.P0)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(this.P5.plus(new BInteger(1))).unequal(prob_oneway8seq.T1.functionCall(this.P1)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(this.P5.plus(new BInteger(1))).unequal(prob_oneway8seq.T2.functionCall(this.P2)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(this.P5.plus(new BInteger(1))).unequal(prob_oneway8seq.T3.functionCall(this.P3)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(this.P5.plus(new BInteger(1))).unequal(prob_oneway8seq.T4.functionCall(this.P4)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(this.P5.plus(new BInteger(1))).unequal(prob_oneway8seq.T6.functionCall(this.P6)).booleanValue()).booleanValue() && prob_oneway8seq.T5.functionCall(this.P5.plus(new BInteger(1))).unequal(prob_oneway8seq.T7.functionCall(this.P7)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A5.functionCall(this.P5.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B5.functionCall(this.P5.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_move6(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P6.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T6.functionCall(this.P6.plus(new BInteger(1))).unequal(prob_oneway8seq.T0.functionCall(this.P0)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(this.P6.plus(new BInteger(1))).unequal(prob_oneway8seq.T1.functionCall(this.P1)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(this.P6.plus(new BInteger(1))).unequal(prob_oneway8seq.T2.functionCall(this.P2)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(this.P6.plus(new BInteger(1))).unequal(prob_oneway8seq.T3.functionCall(this.P3)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(this.P6.plus(new BInteger(1))).unequal(prob_oneway8seq.T4.functionCall(this.P4)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(this.P6.plus(new BInteger(1))).unequal(prob_oneway8seq.T5.functionCall(this.P5)).booleanValue()).booleanValue() && prob_oneway8seq.T6.functionCall(this.P6.plus(new BInteger(1))).unequal(prob_oneway8seq.T7.functionCall(this.P7)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A6.functionCall(this.P6.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B6.functionCall(this.P6.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_move7(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P7.less(new BInteger(6)).booleanValue() && prob_oneway8seq.T7.functionCall(this.P7.plus(new BInteger(1))).unequal(prob_oneway8seq.T0.functionCall(this.P0)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(this.P7.plus(new BInteger(1))).unequal(prob_oneway8seq.T1.functionCall(this.P1)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(this.P7.plus(new BInteger(1))).unequal(prob_oneway8seq.T2.functionCall(this.P2)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(this.P7.plus(new BInteger(1))).unequal(prob_oneway8seq.T3.functionCall(this.P3)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(this.P7.plus(new BInteger(1))).unequal(prob_oneway8seq.T4.functionCall(this.P4)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(this.P7.plus(new BInteger(1))).unequal(prob_oneway8seq.T5.functionCall(this.P5)).booleanValue()).booleanValue() && prob_oneway8seq.T7.functionCall(this.P7.plus(new BInteger(1))).unequal(prob_oneway8seq.T6.functionCall(this.P6)).booleanValue()).booleanValue() && this.RA.plus(prob_oneway8seq.A7.functionCall(this.P7.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LA).booleanValue()).booleanValue() && this.RB.plus(prob_oneway8seq.B7.functionCall(this.P7.plus(new BInteger(1)))).lessEqual(prob_oneway8seq.LB).booleanValue()).booleanValue();
    }

    _tr_arrived(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.P0.equal(new BInteger(6)).booleanValue() && this.P1.equal(new BInteger(6)).booleanValue()).booleanValue() && this.P2.equal(new BInteger(6)).booleanValue()).booleanValue() && this.P3.equal(new BInteger(6)).booleanValue()).booleanValue() && this.P4.equal(new BInteger(6)).booleanValue()).booleanValue() && this.P5.equal(new BInteger(6)).booleanValue()).booleanValue() && this.P6.equal(new BInteger(6)).booleanValue()).booleanValue() && this.P7.equal(new BInteger(6)).booleanValue()).booleanValue();
    }

    _projected_state_for_move5(): _ProjectionRead_move5 {
        return new _ProjectionRead_move5(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for_move6(): _ProjectionRead_move6 {
        return new _ProjectionRead_move6(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for_arrived(): _ProjectionRead_arrived {
        return new _ProjectionRead_arrived(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7);
    }

    _projected_state_for_move7(): _ProjectionRead_move7 {
        return new _ProjectionRead_move7(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for_move1(): _ProjectionRead_move1 {
        return new _ProjectionRead_move1(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for_move2(): _ProjectionRead_move2 {
        return new _ProjectionRead_move2(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for_move3(): _ProjectionRead_move3 {
        return new _ProjectionRead_move3(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for_move4(): _ProjectionRead_move4 {
        return new _ProjectionRead_move4(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for_move0(): _ProjectionRead_move0 {
        return new _ProjectionRead_move0(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_move7(): _ProjectionRead__tr_move7 {
        return new _ProjectionRead__tr_move7(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_arrived(): _ProjectionRead__tr_arrived {
        return new _ProjectionRead__tr_arrived(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7);
    }

    _projected_state_for__tr_move3(): _ProjectionRead__tr_move3 {
        return new _ProjectionRead__tr_move3(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_move4(): _ProjectionRead__tr_move4 {
        return new _ProjectionRead__tr_move4(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_move5(): _ProjectionRead__tr_move5 {
        return new _ProjectionRead__tr_move5(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_move6(): _ProjectionRead__tr_move6 {
        return new _ProjectionRead__tr_move6(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_move0(): _ProjectionRead__tr_move0 {
        return new _ProjectionRead__tr_move0(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_move1(): _ProjectionRead__tr_move1 {
        return new _ProjectionRead__tr_move1(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__tr_move2(): _ProjectionRead__tr_move2 {
        return new _ProjectionRead__tr_move2(this.P0,this.P1,this.P2,this.P3,this.P4,this.P5,this.P6,this.P7,this.RA,this.RB);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.P1);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.P2);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.P0);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.P5);
    }

    _projected_state_for__check_inv_10(): _ProjectionRead__check_inv_10 {
        return new _ProjectionRead__check_inv_10(this.RB);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.P6);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.P3);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.P4);
    }

    _projected_state_for__check_inv_8(): _ProjectionRead__check_inv_8 {
        return new _ProjectionRead__check_inv_8(this.P7);
    }

    _projected_state_for__check_inv_9(): _ProjectionRead__check_inv_9 {
        return new _ProjectionRead__check_inv_9(this.RA);
    }

    _update_for_move5(): _ProjectionWrite_move5 {
        return new _ProjectionWrite_move5(this.RB,this.P5,this.RA);
    }

    _update_for_move6(): _ProjectionWrite_move6 {
        return new _ProjectionWrite_move6(this.RB,this.P6,this.RA);
    }

    _update_for_arrived(): _ProjectionWrite_arrived {
        return new _ProjectionWrite_arrived();
    }

    _update_for_move7(): _ProjectionWrite_move7 {
        return new _ProjectionWrite_move7(this.RB,this.P7,this.RA);
    }

    _update_for_move1(): _ProjectionWrite_move1 {
        return new _ProjectionWrite_move1(this.RB,this.P1,this.RA);
    }

    _update_for_move2(): _ProjectionWrite_move2 {
        return new _ProjectionWrite_move2(this.RB,this.P2,this.RA);
    }

    _update_for_move3(): _ProjectionWrite_move3 {
        return new _ProjectionWrite_move3(this.RB,this.P3,this.RA);
    }

    _update_for_move4(): _ProjectionWrite_move4 {
        return new _ProjectionWrite_move4(this.RB,this.P4,this.RA);
    }

    _update_for_move0(): _ProjectionWrite_move0 {
        return new _ProjectionWrite_move0(this.P0,this.RB,this.RA);
    }

    _apply_update_for_move5(update : _ProjectionWrite_move5): void {
        this.RB = update.RB;
        this.P5 = update.P5;
        this.RA = update.RA;
    }

    _apply_update_for_move6(update : _ProjectionWrite_move6): void {
        this.RB = update.RB;
        this.P6 = update.P6;
        this.RA = update.RA;
    }

    _apply_update_for_arrived(update : _ProjectionWrite_arrived): void {
    }

    _apply_update_for_move7(update : _ProjectionWrite_move7): void {
        this.RB = update.RB;
        this.P7 = update.P7;
        this.RA = update.RA;
    }

    _apply_update_for_move1(update : _ProjectionWrite_move1): void {
        this.RB = update.RB;
        this.P1 = update.P1;
        this.RA = update.RA;
    }

    _apply_update_for_move2(update : _ProjectionWrite_move2): void {
        this.RB = update.RB;
        this.P2 = update.P2;
        this.RA = update.RA;
    }

    _apply_update_for_move3(update : _ProjectionWrite_move3): void {
        this.RB = update.RB;
        this.P3 = update.P3;
        this.RA = update.RA;
    }

    _apply_update_for_move4(update : _ProjectionWrite_move4): void {
        this.RB = update.RB;
        this.P4 = update.P4;
        this.RA = update.RA;
    }

    _apply_update_for_move0(update : _ProjectionWrite_move0): void {
        this.P0 = update.P0;
        this.RB = update.RB;
        this.RA = update.RA;
    }

    _check_inv_1() {
        return new BBoolean(this.P0.greaterEqual(new BInteger(0)).booleanValue() && this.P0.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_2() {
        return new BBoolean(this.P1.greaterEqual(new BInteger(0)).booleanValue() && this.P1.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_3() {
        return new BBoolean(this.P2.greaterEqual(new BInteger(0)).booleanValue() && this.P2.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_4() {
        return new BBoolean(this.P3.greaterEqual(new BInteger(0)).booleanValue() && this.P3.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_5() {
        return new BBoolean(this.P4.greaterEqual(new BInteger(0)).booleanValue() && this.P4.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_6() {
        return new BBoolean(this.P5.greaterEqual(new BInteger(0)).booleanValue() && this.P5.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_7() {
        return new BBoolean(this.P6.greaterEqual(new BInteger(0)).booleanValue() && this.P6.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_8() {
        return new BBoolean(this.P7.greaterEqual(new BInteger(0)).booleanValue() && this.P7.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    _check_inv_9() {
        return new BBoolean(this.RA.greaterEqual(new BInteger(0)).booleanValue() && this.RA.lessEqual(new BInteger(8)).booleanValue()).booleanValue();
    }

    _check_inv_10() {
        return new BBoolean(this.RB.greaterEqual(new BInteger(0)).booleanValue() && this.RB.lessEqual(new BInteger(8)).booleanValue()).booleanValue();
    }


    public _copy(): prob_oneway8seq {
      return new prob_oneway8seq(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<prob_oneway8seq> = new LinkedList<prob_oneway8seq>;
    private states: immutable.Set<prob_oneway8seq> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: prob_oneway8seq = undefined;

    _OpCache_move0: immutable.Map<boolean, immutable.Map<_ProjectionRead_move0, _ProjectionWrite_move0>> = new immutable.Map();
    _OpCache_tr_move0: immutable.Map<_ProjectionRead__tr_move0, boolean> = new immutable.Map();

    _OpCache_move1: immutable.Map<boolean, immutable.Map<_ProjectionRead_move1, _ProjectionWrite_move1>> = new immutable.Map();
    _OpCache_tr_move1: immutable.Map<_ProjectionRead__tr_move1, boolean> = new immutable.Map();

    _OpCache_move2: immutable.Map<boolean, immutable.Map<_ProjectionRead_move2, _ProjectionWrite_move2>> = new immutable.Map();
    _OpCache_tr_move2: immutable.Map<_ProjectionRead__tr_move2, boolean> = new immutable.Map();

    _OpCache_move3: immutable.Map<boolean, immutable.Map<_ProjectionRead_move3, _ProjectionWrite_move3>> = new immutable.Map();
    _OpCache_tr_move3: immutable.Map<_ProjectionRead__tr_move3, boolean> = new immutable.Map();

    _OpCache_move4: immutable.Map<boolean, immutable.Map<_ProjectionRead_move4, _ProjectionWrite_move4>> = new immutable.Map();
    _OpCache_tr_move4: immutable.Map<_ProjectionRead__tr_move4, boolean> = new immutable.Map();

    _OpCache_move5: immutable.Map<boolean, immutable.Map<_ProjectionRead_move5, _ProjectionWrite_move5>> = new immutable.Map();
    _OpCache_tr_move5: immutable.Map<_ProjectionRead__tr_move5, boolean> = new immutable.Map();

    _OpCache_move6: immutable.Map<boolean, immutable.Map<_ProjectionRead_move6, _ProjectionWrite_move6>> = new immutable.Map();
    _OpCache_tr_move6: immutable.Map<_ProjectionRead__tr_move6, boolean> = new immutable.Map();

    _OpCache_move7: immutable.Map<boolean, immutable.Map<_ProjectionRead_move7, _ProjectionWrite_move7>> = new immutable.Map();
    _OpCache_tr_move7: immutable.Map<_ProjectionRead__tr_move7, boolean> = new immutable.Map();

    _OpCache_arrived: immutable.Map<boolean, immutable.Map<_ProjectionRead_arrived, _ProjectionWrite_arrived>> = new immutable.Map();
    _OpCache_tr_arrived: immutable.Map<_ProjectionRead__tr_arrived, boolean> = new immutable.Map();

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
        let machine: prob_oneway8seq = new prob_oneway8seq();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: prob_oneway8seq = this.next();

            let nextStates: Set<prob_oneway8seq> = this.generateNextStates(state);

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

    next(): prob_oneway8seq {
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

    generateNextStates(state: prob_oneway8seq): Set<prob_oneway8seq> {
        let result: immutable.Set<prob_oneway8seq> = immutable.Set();
        if(this.isCaching) {
            let read__tr_move0_state : _ProjectionRead__tr_move0 = state._projected_state_for__tr_move0();
            let _obj__trid_1: any = this._OpCache_tr_move0.get(read__tr_move0_state);
            let _trid_1: boolean;
            if(_obj__trid_1 == null) {
                _trid_1 = state._tr_move0();
                this._OpCache_tr_move0 = this._OpCache_tr_move0.set(read__tr_move0_state, _trid_1);
            } else {
                _trid_1 = _obj__trid_1;
            }

            if(_trid_1) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move0 = state._projected_state_for_move0();
                let _OpCache_with_parameter_move0: immutable.Map = this._OpCache_move0.get(_trid_1);
                if(_OpCache_with_parameter_move0 != null) {
                    let writeState: _ProjectionWrite_move0 = _OpCache_with_parameter_move0.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move0(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move0();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move0();
                        _OpCache_with_parameter_move0 = _OpCache_with_parameter_move0.set(readState, writeState);
                        this._OpCache_move0 = this._OpCache_move0.set(_trid_1, _OpCache_with_parameter_move0);
                    }

                } else {
                    copiedState.move0();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move0 = copiedState._update_for_move0();
                    _OpCache_with_parameter_move0 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move0 = this._OpCache_move0.set(_trid_1, _OpCache_with_parameter_move0);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_move1_state : _ProjectionRead__tr_move1 = state._projected_state_for__tr_move1();
            let _obj__trid_2: any = this._OpCache_tr_move1.get(read__tr_move1_state);
            let _trid_2: boolean;
            if(_obj__trid_2 == null) {
                _trid_2 = state._tr_move1();
                this._OpCache_tr_move1 = this._OpCache_tr_move1.set(read__tr_move1_state, _trid_2);
            } else {
                _trid_2 = _obj__trid_2;
            }

            if(_trid_2) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move1 = state._projected_state_for_move1();
                let _OpCache_with_parameter_move1: immutable.Map = this._OpCache_move1.get(_trid_2);
                if(_OpCache_with_parameter_move1 != null) {
                    let writeState: _ProjectionWrite_move1 = _OpCache_with_parameter_move1.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move1(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move1();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move1();
                        _OpCache_with_parameter_move1 = _OpCache_with_parameter_move1.set(readState, writeState);
                        this._OpCache_move1 = this._OpCache_move1.set(_trid_2, _OpCache_with_parameter_move1);
                    }

                } else {
                    copiedState.move1();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move1 = copiedState._update_for_move1();
                    _OpCache_with_parameter_move1 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move1 = this._OpCache_move1.set(_trid_2, _OpCache_with_parameter_move1);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_move2_state : _ProjectionRead__tr_move2 = state._projected_state_for__tr_move2();
            let _obj__trid_3: any = this._OpCache_tr_move2.get(read__tr_move2_state);
            let _trid_3: boolean;
            if(_obj__trid_3 == null) {
                _trid_3 = state._tr_move2();
                this._OpCache_tr_move2 = this._OpCache_tr_move2.set(read__tr_move2_state, _trid_3);
            } else {
                _trid_3 = _obj__trid_3;
            }

            if(_trid_3) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move2 = state._projected_state_for_move2();
                let _OpCache_with_parameter_move2: immutable.Map = this._OpCache_move2.get(_trid_3);
                if(_OpCache_with_parameter_move2 != null) {
                    let writeState: _ProjectionWrite_move2 = _OpCache_with_parameter_move2.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move2(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move2();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move2();
                        _OpCache_with_parameter_move2 = _OpCache_with_parameter_move2.set(readState, writeState);
                        this._OpCache_move2 = this._OpCache_move2.set(_trid_3, _OpCache_with_parameter_move2);
                    }

                } else {
                    copiedState.move2();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move2 = copiedState._update_for_move2();
                    _OpCache_with_parameter_move2 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move2 = this._OpCache_move2.set(_trid_3, _OpCache_with_parameter_move2);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_move3_state : _ProjectionRead__tr_move3 = state._projected_state_for__tr_move3();
            let _obj__trid_4: any = this._OpCache_tr_move3.get(read__tr_move3_state);
            let _trid_4: boolean;
            if(_obj__trid_4 == null) {
                _trid_4 = state._tr_move3();
                this._OpCache_tr_move3 = this._OpCache_tr_move3.set(read__tr_move3_state, _trid_4);
            } else {
                _trid_4 = _obj__trid_4;
            }

            if(_trid_4) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move3 = state._projected_state_for_move3();
                let _OpCache_with_parameter_move3: immutable.Map = this._OpCache_move3.get(_trid_4);
                if(_OpCache_with_parameter_move3 != null) {
                    let writeState: _ProjectionWrite_move3 = _OpCache_with_parameter_move3.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move3(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move3();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move3();
                        _OpCache_with_parameter_move3 = _OpCache_with_parameter_move3.set(readState, writeState);
                        this._OpCache_move3 = this._OpCache_move3.set(_trid_4, _OpCache_with_parameter_move3);
                    }

                } else {
                    copiedState.move3();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move3 = copiedState._update_for_move3();
                    _OpCache_with_parameter_move3 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move3 = this._OpCache_move3.set(_trid_4, _OpCache_with_parameter_move3);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_move4_state : _ProjectionRead__tr_move4 = state._projected_state_for__tr_move4();
            let _obj__trid_5: any = this._OpCache_tr_move4.get(read__tr_move4_state);
            let _trid_5: boolean;
            if(_obj__trid_5 == null) {
                _trid_5 = state._tr_move4();
                this._OpCache_tr_move4 = this._OpCache_tr_move4.set(read__tr_move4_state, _trid_5);
            } else {
                _trid_5 = _obj__trid_5;
            }

            if(_trid_5) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move4 = state._projected_state_for_move4();
                let _OpCache_with_parameter_move4: immutable.Map = this._OpCache_move4.get(_trid_5);
                if(_OpCache_with_parameter_move4 != null) {
                    let writeState: _ProjectionWrite_move4 = _OpCache_with_parameter_move4.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move4(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move4();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move4();
                        _OpCache_with_parameter_move4 = _OpCache_with_parameter_move4.set(readState, writeState);
                        this._OpCache_move4 = this._OpCache_move4.set(_trid_5, _OpCache_with_parameter_move4);
                    }

                } else {
                    copiedState.move4();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move4 = copiedState._update_for_move4();
                    _OpCache_with_parameter_move4 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move4 = this._OpCache_move4.set(_trid_5, _OpCache_with_parameter_move4);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_move5_state : _ProjectionRead__tr_move5 = state._projected_state_for__tr_move5();
            let _obj__trid_6: any = this._OpCache_tr_move5.get(read__tr_move5_state);
            let _trid_6: boolean;
            if(_obj__trid_6 == null) {
                _trid_6 = state._tr_move5();
                this._OpCache_tr_move5 = this._OpCache_tr_move5.set(read__tr_move5_state, _trid_6);
            } else {
                _trid_6 = _obj__trid_6;
            }

            if(_trid_6) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move5 = state._projected_state_for_move5();
                let _OpCache_with_parameter_move5: immutable.Map = this._OpCache_move5.get(_trid_6);
                if(_OpCache_with_parameter_move5 != null) {
                    let writeState: _ProjectionWrite_move5 = _OpCache_with_parameter_move5.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move5(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move5();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move5();
                        _OpCache_with_parameter_move5 = _OpCache_with_parameter_move5.set(readState, writeState);
                        this._OpCache_move5 = this._OpCache_move5.set(_trid_6, _OpCache_with_parameter_move5);
                    }

                } else {
                    copiedState.move5();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move5 = copiedState._update_for_move5();
                    _OpCache_with_parameter_move5 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move5 = this._OpCache_move5.set(_trid_6, _OpCache_with_parameter_move5);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_move6_state : _ProjectionRead__tr_move6 = state._projected_state_for__tr_move6();
            let _obj__trid_7: any = this._OpCache_tr_move6.get(read__tr_move6_state);
            let _trid_7: boolean;
            if(_obj__trid_7 == null) {
                _trid_7 = state._tr_move6();
                this._OpCache_tr_move6 = this._OpCache_tr_move6.set(read__tr_move6_state, _trid_7);
            } else {
                _trid_7 = _obj__trid_7;
            }

            if(_trid_7) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move6 = state._projected_state_for_move6();
                let _OpCache_with_parameter_move6: immutable.Map = this._OpCache_move6.get(_trid_7);
                if(_OpCache_with_parameter_move6 != null) {
                    let writeState: _ProjectionWrite_move6 = _OpCache_with_parameter_move6.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move6(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move6();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move6();
                        _OpCache_with_parameter_move6 = _OpCache_with_parameter_move6.set(readState, writeState);
                        this._OpCache_move6 = this._OpCache_move6.set(_trid_7, _OpCache_with_parameter_move6);
                    }

                } else {
                    copiedState.move6();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move6 = copiedState._update_for_move6();
                    _OpCache_with_parameter_move6 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move6 = this._OpCache_move6.set(_trid_7, _OpCache_with_parameter_move6);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_move7_state : _ProjectionRead__tr_move7 = state._projected_state_for__tr_move7();
            let _obj__trid_8: any = this._OpCache_tr_move7.get(read__tr_move7_state);
            let _trid_8: boolean;
            if(_obj__trid_8 == null) {
                _trid_8 = state._tr_move7();
                this._OpCache_tr_move7 = this._OpCache_tr_move7.set(read__tr_move7_state, _trid_8);
            } else {
                _trid_8 = _obj__trid_8;
            }

            if(_trid_8) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_move7 = state._projected_state_for_move7();
                let _OpCache_with_parameter_move7: immutable.Map = this._OpCache_move7.get(_trid_8);
                if(_OpCache_with_parameter_move7 != null) {
                    let writeState: _ProjectionWrite_move7 = _OpCache_with_parameter_move7.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_move7(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.move7();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_move7();
                        _OpCache_with_parameter_move7 = _OpCache_with_parameter_move7.set(readState, writeState);
                        this._OpCache_move7 = this._OpCache_move7.set(_trid_8, _OpCache_with_parameter_move7);
                    }

                } else {
                    copiedState.move7();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_move7 = copiedState._update_for_move7();
                    _OpCache_with_parameter_move7 = new immutable.Map().set(readState, writeState);
                    this._OpCache_move7 = this._OpCache_move7.set(_trid_8, _OpCache_with_parameter_move7);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_arrived_state : _ProjectionRead__tr_arrived = state._projected_state_for__tr_arrived();
            let _obj__trid_9: any = this._OpCache_tr_arrived.get(read__tr_arrived_state);
            let _trid_9: boolean;
            if(_obj__trid_9 == null) {
                _trid_9 = state._tr_arrived();
                this._OpCache_tr_arrived = this._OpCache_tr_arrived.set(read__tr_arrived_state, _trid_9);
            } else {
                _trid_9 = _obj__trid_9;
            }

            if(_trid_9) {
                let copiedState: prob_oneway8seq = state._copy();
                let readState: _ProjectionRead_arrived = state._projected_state_for_arrived();
                let _OpCache_with_parameter_arrived: immutable.Map = this._OpCache_arrived.get(_trid_9);
                if(_OpCache_with_parameter_arrived != null) {
                    let writeState: _ProjectionWrite_arrived = _OpCache_with_parameter_arrived.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_arrived(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.arrived();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_arrived();
                        _OpCache_with_parameter_arrived = _OpCache_with_parameter_arrived.set(readState, writeState);
                        this._OpCache_arrived = this._OpCache_arrived.set(_trid_9, _OpCache_with_parameter_arrived);
                    }

                } else {
                    copiedState.arrived();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_arrived = copiedState._update_for_arrived();
                    _OpCache_with_parameter_arrived = new immutable.Map().set(readState, writeState);
                    this._OpCache_arrived = this._OpCache_arrived.set(_trid_9, _OpCache_with_parameter_arrived);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            if(state._tr_move0()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move0();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_move1()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move1();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_move2()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move2();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_move3()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move3();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_move4()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move4();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_move5()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move5();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_move6()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move6();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_move7()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.move7();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_arrived()) {
                let copiedState: prob_oneway8seq = state._copy();
                copiedState.arrived();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: prob_oneway8seq): boolean {
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

