import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";




class _ProjectionRead_inc {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_inc = this;
        let o2: _ProjectionRead_inc = other as _ProjectionRead_inc;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_inc {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_inc = this;
        let o2: _ProjectionRead__tr_inc = other as _ProjectionRead__tr_inc;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_inc {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_inc = this;
        let o2: _ProjectionWrite_inc = other as _ProjectionWrite_inc;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_dec {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_dec = this;
        let o2: _ProjectionRead_dec = other as _ProjectionRead_dec;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_dec {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_dec = this;
        let o2: _ProjectionRead__tr_dec = other as _ProjectionRead__tr_dec;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_dec {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_dec = this;
        let o2: _ProjectionWrite_dec = other as _ProjectionWrite_dec;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public level: BInteger;

    constructor(level : BInteger) {
        this.level = level;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.level.equals(o2.level);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.level.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class Lift_MC_Large {

    parent: Lift_MC_Large;
    stateAccessedVia: string;




    private level: BInteger;

    constructor(copy? : Lift_MC_Large) {
        if(copy) {
            this.level = copy.level;
        } else {
            this.level = new BInteger(0);
        }
    }



    inc(): void {
        this.level = this.level.plus(new BInteger(1));

    }

    dec(): void {
        this.level = this.level.minus(new BInteger(1));

    }

    _get_level(): BInteger {
        return this.level;
    }

    _tr_inc(): boolean {
        return this.level.less(new BInteger(1000000)).booleanValue();
    }

    _tr_dec(): boolean {
        return this.level.greater(new BInteger(0)).booleanValue();
    }

    _projected_state_for_dec(): _ProjectionRead_dec {
        return new _ProjectionRead_dec(this.level);
    }

    _projected_state_for_inc(): _ProjectionRead_inc {
        return new _ProjectionRead_inc(this.level);
    }

    _projected_state_for__tr_dec(): _ProjectionRead__tr_dec {
        return new _ProjectionRead__tr_dec(this.level);
    }

    _projected_state_for__tr_inc(): _ProjectionRead__tr_inc {
        return new _ProjectionRead__tr_inc(this.level);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.level);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.level);
    }

    _update_for_dec(): _ProjectionWrite_dec {
        return new _ProjectionWrite_dec(this.level);
    }

    _update_for_inc(): _ProjectionWrite_inc {
        return new _ProjectionWrite_inc(this.level);
    }

    _apply_update_for_dec(update : _ProjectionWrite_dec): void {
        this.level = update.level;
    }

    _apply_update_for_inc(update : _ProjectionWrite_inc): void {
        this.level = update.level;
    }

    _check_inv_1() {
        return this.level.greaterEqual(new BInteger(0)).booleanValue();
    }

    _check_inv_2() {
        return this.level.lessEqual(new BInteger(1000000)).booleanValue();
    }

    equals(o: any): boolean {
        let o1: Lift_MC_Large = this;
        let o2: Lift_MC_Large = o as Lift_MC_Large;
        return o1._get_level().equals(o2._get_level());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_level()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_level()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_level: " + (this._get_level()).toString());
    }
    */


    public _copy(): Lift_MC_Large {
      return new Lift_MC_Large(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<Lift_MC_Large> = new LinkedList<Lift_MC_Large>;
    private states: immutable.Set<Lift_MC_Large> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: Lift_MC_Large = undefined;

    _OpCache_inc: immutable.Map<boolean, immutable.Map<_ProjectionRead_inc, _ProjectionWrite_inc>> = new immutable.Map();
    _OpCache_tr_inc: immutable.Map<_ProjectionRead__tr_inc, boolean> = new immutable.Map();

    _OpCache_dec: immutable.Map<boolean, immutable.Map<_ProjectionRead_dec, _ProjectionWrite_dec>> = new immutable.Map();
    _OpCache_tr_dec: immutable.Map<_ProjectionRead__tr_dec, boolean> = new immutable.Map();

    _InvCache__check_inv_1: immutable.Map<_ProjectionRead__check_inv_1, boolean> = new immutable.Map();
    _InvCache__check_inv_2: immutable.Map<_ProjectionRead__check_inv_2, boolean> = new immutable.Map();

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
        let machine: Lift_MC_Large = new Lift_MC_Large();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: Lift_MC_Large = this.next();

            let nextStates: Set<Lift_MC_Large> = this.generateNextStates(state);

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

    next(): Lift_MC_Large {
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

    generateNextStates(state: Lift_MC_Large): Set<Lift_MC_Large> {
        let result: immutable.Set<Lift_MC_Large> = immutable.Set();
        if(this.isCaching) {
            let read__tr_inc_state : _ProjectionRead__tr_inc = state._projected_state_for__tr_inc();
            let _obj__trid_1: any = this._OpCache_tr_inc.get(read__tr_inc_state);
            let _trid_1: boolean;
            if(_obj__trid_1 == null) {
                _trid_1 = state._tr_inc();
                this._OpCache_tr_inc = this._OpCache_tr_inc.set(read__tr_inc_state, _trid_1);
            } else {
                _trid_1 = _obj__trid_1;
            }

            if(_trid_1) {
                let copiedState: Lift_MC_Large = state._copy();
                let readState: _ProjectionRead_inc = state._projected_state_for_inc();
                let _OpCache_with_parameter_inc: immutable.Map = this._OpCache_inc.get(_trid_1);
                if(_OpCache_with_parameter_inc != null) {
                    let writeState: _ProjectionWrite_inc = _OpCache_with_parameter_inc.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_inc(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.inc();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_inc();
                        _OpCache_with_parameter_inc = _OpCache_with_parameter_inc.set(readState, writeState);
                        this._OpCache_inc = this._OpCache_inc.set(_trid_1, _OpCache_with_parameter_inc);
                    }

                } else {
                    copiedState.inc();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_inc = copiedState._update_for_inc();
                    _OpCache_with_parameter_inc = new immutable.Map().set(readState, writeState);
                    this._OpCache_inc = this._OpCache_inc.set(_trid_1, _OpCache_with_parameter_inc);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_dec_state : _ProjectionRead__tr_dec = state._projected_state_for__tr_dec();
            let _obj__trid_2: any = this._OpCache_tr_dec.get(read__tr_dec_state);
            let _trid_2: boolean;
            if(_obj__trid_2 == null) {
                _trid_2 = state._tr_dec();
                this._OpCache_tr_dec = this._OpCache_tr_dec.set(read__tr_dec_state, _trid_2);
            } else {
                _trid_2 = _obj__trid_2;
            }

            if(_trid_2) {
                let copiedState: Lift_MC_Large = state._copy();
                let readState: _ProjectionRead_dec = state._projected_state_for_dec();
                let _OpCache_with_parameter_dec: immutable.Map = this._OpCache_dec.get(_trid_2);
                if(_OpCache_with_parameter_dec != null) {
                    let writeState: _ProjectionWrite_dec = _OpCache_with_parameter_dec.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_dec(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.dec();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_dec();
                        _OpCache_with_parameter_dec = _OpCache_with_parameter_dec.set(readState, writeState);
                        this._OpCache_dec = this._OpCache_dec.set(_trid_2, _OpCache_with_parameter_dec);
                    }

                } else {
                    copiedState.dec();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_dec = copiedState._update_for_dec();
                    _OpCache_with_parameter_dec = new immutable.Map().set(readState, writeState);
                    this._OpCache_dec = this._OpCache_dec.set(_trid_2, _OpCache_with_parameter_dec);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            if(state._tr_inc()) {
                let copiedState: Lift_MC_Large = state._copy();
                copiedState.inc();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_dec()) {
                let copiedState: Lift_MC_Large = state._copy();
                copiedState.dec();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: Lift_MC_Large): boolean {
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

