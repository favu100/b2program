import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BRelation} from './btypes/BRelation.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BUtils} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";




export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class sort_m2_data1000_MC {

    parent: sort_m2_data1000_MC;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;


    private static n: BInteger;
    private static f: BRelation<BInteger, BInteger>;


    private j: BInteger;
    private k: BInteger;
    private l: BInteger;
    private g: BRelation<BInteger, BInteger>;

    constructor() {
        sort_m2_data1000_MC.n = new BInteger(1000);
        let _ic_set_0: BRelation<BInteger, BInteger> = new BRelation<BInteger, BInteger>();
        for(let _ic_i_1 of BSet.interval(new BInteger(1), sort_m2_data1000_MC.n)) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple(_ic_i_1, new BInteger(15000).minus(_ic_i_1))));

        }
        sort_m2_data1000_MC.f = _ic_set_0;
        this.g = sort_m2_data1000_MC.f;
        this.k = new BInteger(1);
        this.l = new BInteger(1);
        this.j = new BInteger(1);
    }


     progress(): void {
        let _ld_l: BInteger = this.l;
        let _ld_g: BRelation<BInteger, BInteger> = this.g;
        let _ld_k: BInteger = this.k;
        this.g = _ld_g.override(new BRelation<BInteger, BInteger>(new BTuple(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation<BInteger, BInteger>(new BTuple(_ld_l, _ld_g.functionCall(_ld_k)))));
        this.k = _ld_k.plus(new BInteger(1));
        this.j = _ld_k.plus(new BInteger(1));
        this.l = _ld_k.plus(new BInteger(1));

    }

     prog1(): void {
        let _ld_j: BInteger = this.j;
        let _ld_l: BInteger = this.l;
        this.l = _ld_l;
        this.j = _ld_j.plus(new BInteger(1));

    }

     prog2(): void {
        let _ld_j: BInteger = this.j;
        this.j = _ld_j.plus(new BInteger(1));
        this.l = _ld_j.plus(new BInteger(1));

    }

     final_evt(): void {
    }

    _get_n(): BInteger {
        return sort_m2_data1000_MC.n;
    }

    _get_f(): BRelation<BInteger, BInteger> {
        return sort_m2_data1000_MC.f;
    }

    _get_j(): BInteger {
        return this.j;
    }

    _get_k(): BInteger {
        return this.k;
    }

    _get_l(): BInteger {
        return this.l;
    }

    _get_g(): BRelation<BInteger, BInteger> {
        return this.g;
    }

    _tr_progress(): boolean {
        return new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.equal(sort_m2_data1000_MC.n).booleanValue()).booleanValue();
    }

    _tr_prog1(): boolean {
        return new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.unequal(sort_m2_data1000_MC.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).lessEqual(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    _tr_prog2(): boolean {
        return new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.unequal(sort_m2_data1000_MC.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).greater(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    _tr_final_evt(): boolean {
        return this.k.equal(sort_m2_data1000_MC.n).booleanValue();
    }

    _check_inv_1() {
        return this.j.greaterEqual(this.k).booleanValue();
    }

    _check_inv_2() {
        return this.j.lessEqual(sort_m2_data1000_MC.n).booleanValue();
    }

    _check_inv_3() {
        return this.l.greaterEqual(this.k).booleanValue();
    }

    _check_inv_4() {
        return this.j.lessEqual(this.j).booleanValue();
    }

    _check_inv_5() {
        return this.g.functionCall(this.l).equal(this.g.relationImage(BSet.interval(this.k, this.j)).min()).booleanValue();
    }

    _check_inv_6() {
        return this.g.checkDomain(BSet.interval(new BInteger(1), sort_m2_data1000_MC.n)).and(this.g.checkRangeNatural()).and(this.g.isFunction()).and(this.g.isTotal(BSet.interval(new BInteger(1), sort_m2_data1000_MC.n))).booleanValue();
    }

    equals(o: any): boolean {
        let o1: sort_m2_data1000_MC = this;
        let o2: sort_m2_data1000_MC = o as sort_m2_data1000_MC;
        return o1._get_n().equals(o2._get_n()) && o1._get_f().equals(o2._get_f()) && o1._get_j().equals(o2._get_j()) && o1._get_k().equals(o2._get_k()) && o1._get_l().equals(o2._get_l()) && o1._get_g().equals(o2._get_g());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_j: " + (this._get_j()).toString(), "_get_k: " + (this._get_k()).toString(), "_get_l: " + (this._get_l()).toString(), "_get_g: " + (this._get_g()).toString());
    }
    */


    public _copy(): sort_m2_data1000_MC {
      const _instance = new sort_m2_data1000_MC();
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

    private unvisitedStates: LinkedList<sort_m2_data1000_MC> = new LinkedList<sort_m2_data1000_MC>;
    private states: immutable.Set<sort_m2_data1000_MC> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: sort_m2_data1000_MC = undefined;

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
        let machine: sort_m2_data1000_MC = new sort_m2_data1000_MC();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        if(this.isCaching) {
            this.initCache(machine);
        }

        while(!(this.unvisitedStates.length === 0)) {
            let state: sort_m2_data1000_MC = this.next();

            let nextStates: Set<sort_m2_data1000_MC> = this.generateNextStates(state);

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

    initCache(machine: sort_m2_data1000_MC ): void {
        this.invariantDependency = this.invariantDependency.set("prog2", immutable.Set(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("prog1", immutable.Set(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("progress", immutable.Set(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("final_evt", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("prog2", immutable.Set(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
        this.guardDependency = this.guardDependency.set("prog1", immutable.Set(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
        this.guardDependency = this.guardDependency.set("progress", immutable.Set(["_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"]));
        this.guardDependency = this.guardDependency.set("final_evt", immutable.Set([]));
    }

    next(): sort_m2_data1000_MC {
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

    generateNextStates(state: sort_m2_data1000_MC): Set<sort_m2_data1000_MC> {
        let result: immutable.Set<sort_m2_data1000_MC> = immutable.Set();
        if(this.isCaching) {
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_progress");
                dependentGuardsBoolean = "_tr_progress" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_progress();
            } else {
                _trid_1 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_progress", _trid_1);
            if(_trid_1) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.progress();
                copiedState.parent = state;
                this.addCachedInfos("progress", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_prog1");
                dependentGuardsBoolean = "_tr_prog1" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_prog1();
            } else {
                _trid_2 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_prog1", _trid_2);
            if(_trid_2) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.prog1();
                copiedState.parent = state;
                this.addCachedInfos("prog1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_prog2");
                dependentGuardsBoolean = "_tr_prog2" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_prog2();
            } else {
                _trid_3 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_prog2", _trid_3);
            if(_trid_3) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.prog2();
                copiedState.parent = state;
                this.addCachedInfos("prog2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_final_evt");
                dependentGuardsBoolean = "_tr_final_evt" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_final_evt();
            } else {
                _trid_4 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_final_evt", _trid_4);
            if(_trid_4) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.final_evt();
                copiedState.parent = state;
                this.addCachedInfos("final_evt", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            if(state._tr_progress()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.progress();
                copiedState.parent = state;
                this.addCachedInfos("progress", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_prog1()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.prog1();
                copiedState.parent = state;
                this.addCachedInfos("prog1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_prog2()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.prog2();
                copiedState.parent = state;
                this.addCachedInfos("prog2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_final_evt()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.final_evt();
                copiedState.parent = state;
                this.addCachedInfos("final_evt", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: sort_m2_data1000_MC): boolean {
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
        return false;
    }

    addCachedInfos(operation: string, state: sort_m2_data1000_MC, copiedState: sort_m2_data1000_MC): void {
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

