import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BUtils} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";




export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class Lift_MC_Large {

    parent: Lift_MC_Large;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;




    private level: BInteger;

    constructor() {
        this.level = new BInteger(0);
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
      const _instance = new Lift_MC_Large();
      for (const key of Object.keys(this)) {
        _instance[key] = this[key];
      }
      return _instance;
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
        let machine: Lift_MC_Large = new Lift_MC_Large();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        if(this.isCaching) {
            this.initCache(machine);
        }

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

    initCache(machine: Lift_MC_Large ): void {
        this.invariantDependency = this.invariantDependency.set("dec", immutable.Set(["_check_inv_2", "_check_inv_1"]));
        this.invariantDependency = this.invariantDependency.set("inc", immutable.Set(["_check_inv_2", "_check_inv_1"]));
        this.guardDependency = this.guardDependency.set("dec", immutable.Set(["_tr_dec", "_tr_inc"]));
        this.guardDependency = this.guardDependency.set("inc", immutable.Set(["_tr_dec", "_tr_inc"]));
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
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_inc");
                dependentGuardsBoolean = "_tr_inc" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_inc();
            } else {
                _trid_1 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_inc", _trid_1);
            if(_trid_1) {
                let copiedState: Lift_MC_Large = state._copy();
                copiedState.inc();
                copiedState.parent = state;
                this.addCachedInfos("inc", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_dec");
                dependentGuardsBoolean = "_tr_dec" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_dec();
            } else {
                _trid_2 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_dec", _trid_2);
            if(_trid_2) {
                let copiedState: Lift_MC_Large = state._copy();
                copiedState.dec();
                copiedState.parent = state;
                this.addCachedInfos("dec", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            if(state._tr_inc()) {
                let copiedState: Lift_MC_Large = state._copy();
                copiedState.inc();
                copiedState.parent = state;
                this.addCachedInfos("inc", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_dec()) {
                let copiedState: Lift_MC_Large = state._copy();
                copiedState.dec();
                copiedState.parent = state;
                this.addCachedInfos("dec", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: Lift_MC_Large): boolean {
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
        return false;
    }

    addCachedInfos(operation: string, state: Lift_MC_Large, copiedState: Lift_MC_Large): void {
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

