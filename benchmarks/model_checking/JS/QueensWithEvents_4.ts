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

export default class QueensWithEvents_4 {

    parent: QueensWithEvents_4;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;


    private static n: BInteger;
    private static interval: BSet<BInteger>;
    private static allFields: BSet<BRelation<BInteger, BInteger>>;


    private queens: BRelation<BInteger, BInteger>;

    static {
        QueensWithEvents_4.n = new BInteger(4);
        QueensWithEvents_4.interval = BSet.interval(new BInteger(1), QueensWithEvents_4.n);
        QueensWithEvents_4.allFields = BRelation.cartesianProduct(QueensWithEvents_4.interval, QueensWithEvents_4.interval).pow();
    }

    constructor() {
        this.queens = new BRelation<BInteger, BInteger>();
    }


     Solve(solution: BRelation<BInteger, BInteger>): void {
        this.queens = solution;

    }

    _get_n(): BInteger {
        return QueensWithEvents_4.n;
    }

    _get_interval(): BSet<BInteger> {
        return QueensWithEvents_4.interval;
    }

    _get_allFields(): BSet<BRelation<BInteger, BInteger>> {
        return QueensWithEvents_4.allFields;
    }

    _get_queens(): BRelation<BInteger, BInteger> {
        return this.queens;
    }

    _tr_Solve(): BSet<BRelation<BInteger, BInteger>> {
        let _ic_set_4: BSet<BRelation<BInteger, BInteger>> = new BSet<BRelation<BInteger, BInteger>>();
        for(let _ic_solution_1 of QueensWithEvents_4.allFields) {
            let _ic_boolean_5: BBoolean = new BBoolean(true);
            for(let _ic_x_1 of QueensWithEvents_4.interval) {
                for(let _ic_y_1 of QueensWithEvents_4.interval) {
                    let _ic_boolean_4: BBoolean = new BBoolean(true);
                    for(let _ic_z_1 of QueensWithEvents_4.interval) {
                        if(!(new BBoolean(!_ic_solution_1.elementOf(new BTuple(_ic_x_1, _ic_z_1)).booleanValue() || _ic_y_1.equal(_ic_z_1).booleanValue())).booleanValue()) {
                            _ic_boolean_4 = new BBoolean(false);
                            break;
                        }

                    }
                    if(new BBoolean(_ic_solution_1.domain().equal(QueensWithEvents_4.interval).booleanValue() && _ic_solution_1.range().equal(QueensWithEvents_4.interval).booleanValue()).booleanValue()) {
                        if(!(new BBoolean(!_ic_solution_1.elementOf(new BTuple(_ic_x_1, _ic_y_1)).booleanValue() || _ic_boolean_4.booleanValue())).booleanValue()) {
                            _ic_boolean_5 = new BBoolean(false);
                            break;
                        }
                    }

                }
            }let _ic_boolean_6: BBoolean = new BBoolean(true);
            for(let _ic_q1_1 of QueensWithEvents_4.interval) {
                for(let _ic_q2_1 of QueensWithEvents_4.interval.difference(new BSet<BInteger>(new BInteger(1)))) {
                    if(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(QueensWithEvents_4.interval).booleanValue() && _ic_solution_1.range().equal(QueensWithEvents_4.interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue()) {
                        if(!(new BBoolean(!_ic_q2_1.greater(_ic_q1_1).booleanValue() || new BBoolean(_ic_solution_1.functionCall(_ic_q1_1).plus(_ic_q2_1).minus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue() && _ic_solution_1.functionCall(_ic_q1_1).minus(_ic_q2_1).plus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue()).booleanValue())).booleanValue()) {
                            _ic_boolean_6 = new BBoolean(false);
                            break;
                        }
                    }

                }
            }let _ic_boolean_7: BBoolean = new BBoolean(true);
            for(let _ic_x_1 of this.queens.domain()) {
                if(new BBoolean(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(QueensWithEvents_4.interval).booleanValue() && _ic_solution_1.range().equal(QueensWithEvents_4.interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue()) {
                    if(!(_ic_solution_1.functionCall(_ic_x_1).equal(this.queens.functionCall(_ic_x_1))).booleanValue()) {
                        _ic_boolean_7 = new BBoolean(false);
                        break;
                    }
                }

            }
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(QueensWithEvents_4.interval).booleanValue() && _ic_solution_1.range().equal(QueensWithEvents_4.interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue())).booleanValue()) {
                _ic_set_4 = _ic_set_4.union(new BSet<BRelation<BInteger, BInteger>>(_ic_solution_1));
            }

        }
        return _ic_set_4;
    }

    _check_inv_1() {
        return this.queens.checkDomain(QueensWithEvents_4.interval).and(this.queens.checkRange(QueensWithEvents_4.interval)).and(this.queens.isFunction()).and(this.queens.isPartial(QueensWithEvents_4.interval)).booleanValue();
    }

    equals(o: any): boolean {
        let o1: QueensWithEvents_4 = this;
        let o2: QueensWithEvents_4 = o as QueensWithEvents_4;
        return o1._get_queens().equals(o2._get_queens());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_queens()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_queens()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_queens: " + (this._get_queens()).toString());
    }
    */


    public _copy(): QueensWithEvents_4 {
      const _instance = new QueensWithEvents_4();
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

    private unvisitedStates: LinkedList<QueensWithEvents_4> = new LinkedList<QueensWithEvents_4>;
    private states: immutable.Set<QueensWithEvents_4> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: QueensWithEvents_4 = undefined;

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
        let machine: QueensWithEvents_4 = new QueensWithEvents_4();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        if(this.isCaching) {
            this.initCache(machine);
        }

        while(!(this.unvisitedStates.length === 0)) {
            let state: QueensWithEvents_4 = this.next();

            let nextStates: Set<QueensWithEvents_4> = this.generateNextStates(state);

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

    initCache(machine: QueensWithEvents_4 ): void {
        this.invariantDependency = this.invariantDependency.set("Solve", immutable.Set(["_check_inv_1"]));
        this.guardDependency = this.guardDependency.set("Solve", immutable.Set(["_tr_Solve"]));
    }

    next(): QueensWithEvents_4 {
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

    generateNextStates(state: QueensWithEvents_4): Set<QueensWithEvents_4> {
        let result: immutable.Set<QueensWithEvents_4> = immutable.Set();
        if(this.isCaching) {
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: BSet<BRelation<BInteger, BInteger>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_Solve");
                dependentGuardsBoolean = "_tr_Solve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_Solve();
            } else {
                _trid_1 = cachedValue as BSet<BRelation<BInteger, BInteger>>;
            }
            newCache = newCache.set("_tr_Solve", _trid_1);
            for(let param of _trid_1) {
                let _tmp_1: BRelation<BInteger, BInteger> = param;

                let copiedState: QueensWithEvents_4 = state._copy();
                copiedState.Solve(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("Solve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            let _trid_1: BSet<BRelation<BInteger, BInteger>> = state._tr_Solve();
            for(let param of _trid_1) {
                let _tmp_1: BRelation<BInteger, BInteger> = param;

                let copiedState: QueensWithEvents_4 = state._copy();
                copiedState.Solve(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("Solve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: QueensWithEvents_4): boolean {
        if(!(this.isCaching) || "_check_inv_1" in state.dependentInvariant) {
            if(!state._check_inv_1()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
        }
        return false;
    }

    addCachedInfos(operation: string, state: QueensWithEvents_4, copiedState: QueensWithEvents_4): void {
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

