import { BTuple } from './btypes/BTuple.js';
import { BInteger } from './btypes/BInteger.js';
import { BRelation } from './btypes/BRelation.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
import * as immutable from "./immutable/dist/immutable.es.js";
import { LinkedList } from "./modelchecking/LinkedList.js";
export var Type;
(function (Type) {
    Type[Type["BFS"] = 0] = "BFS";
    Type[Type["DFS"] = 1] = "DFS";
    Type[Type["MIXED"] = 2] = "MIXED";
})(Type || (Type = {}));
export default class sort_m2_data1000_MC {
    constructor(copy) {
        this.dependentGuard = immutable.Set();
        this.guardCache = immutable.Map();
        this.dependentInvariant = immutable.Set();
        if (copy) {
            this.j = copy.j;
            this.k = copy.k;
            this.l = copy.l;
            this.g = copy.g;
        }
        else {
            this.g = sort_m2_data1000_MC.f;
            this.k = new BInteger(1);
            this.l = new BInteger(1);
            this.j = new BInteger(1);
        }
    }
    progress() {
        let _ld_l = this.l;
        let _ld_g = this.g;
        let _ld_k = this.k;
        this.g = _ld_g.override(new BRelation(new BTuple(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation(new BTuple(_ld_l, _ld_g.functionCall(_ld_k)))));
        this.k = _ld_k.plus(new BInteger(1));
        this.j = _ld_k.plus(new BInteger(1));
        this.l = _ld_k.plus(new BInteger(1));
    }
    prog1() {
        let _ld_j = this.j;
        let _ld_l = this.l;
        this.l = _ld_l;
        this.j = _ld_j.plus(new BInteger(1));
    }
    prog2() {
        let _ld_j = this.j;
        this.j = _ld_j.plus(new BInteger(1));
        this.l = _ld_j.plus(new BInteger(1));
    }
    final_evt() {
    }
    _get_n() {
        return sort_m2_data1000_MC.n;
    }
    _get_f() {
        return sort_m2_data1000_MC.f;
    }
    _get_j() {
        return this.j;
    }
    _get_k() {
        return this.k;
    }
    _get_l() {
        return this.l;
    }
    _get_g() {
        return this.g;
    }
    _tr_progress() {
        return new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.equal(sort_m2_data1000_MC.n).booleanValue()).booleanValue();
    }
    _tr_prog1() {
        return new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.unequal(sort_m2_data1000_MC.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).lessEqual(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }
    _tr_prog2() {
        return new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.unequal(sort_m2_data1000_MC.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).greater(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }
    _tr_final_evt() {
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
    equals(o) {
        let o1 = this;
        let o2 = o;
        return o1._get_j().equals(o2._get_j()) && o1._get_k().equals(o2._get_k()) && o1._get_l().equals(o2._get_l()) && o1._get_g().equals(o2._get_g());
    }
    hashCode() {
        return this._hashCode_1();
    }
    _hashCode_1() {
        let result = 1;
        result = (1543 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }
    _hashCode_2() {
        let result = 1;
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
    _copy() {
        return new sort_m2_data1000_MC(this);
    }
}
(() => {
    sort_m2_data1000_MC.n = new BInteger(1000);
    let _ic_set_0 = new BRelation();
    for (let _ic_i_1 of BSet.interval(new BInteger(1), sort_m2_data1000_MC.n)) {
        _ic_set_0 = _ic_set_0.union(new BRelation(new BTuple(_ic_i_1, new BInteger(15000).minus(_ic_i_1))));
    }
    sort_m2_data1000_MC.f = _ic_set_0;
})();
export class ModelChecker {
    constructor(type, isCaching, isDebug) {
        this.unvisitedStates = new LinkedList;
        this.states = new immutable.Set();
        this.transitions = 0;
        this.invariantViolated = false;
        this.deadlockDetected = false;
        this.counterExampleState = undefined;
        this.invariantDependency = new immutable.Map();
        this.guardDependency = new immutable.Map();
        this.type = type;
        this.isCaching = isCaching;
        this.isDebug = isDebug;
    }
    modelCheck() {
        if (this.isDebug) {
            console.log("Starting Modelchecking, STRATEGY=" + this.type + ", CACHING=" + this.isCaching);
        }
        this.modelCheckSingleThreaded();
    }
    modelCheckSingleThreaded() {
        let machine = new sort_m2_data1000_MC();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);
        if (this.isCaching) {
            this.initCache(machine);
        }
        while (!(this.unvisitedStates.length === 0)) {
            let state = this.next();
            let nextStates = this.generateNextStates(state);
            for (let nextState of nextStates) {
                if (!this.states.has(nextState)) {
                    this.states = this.states.add(nextState);
                    this.unvisitedStates.pushBack(nextState);
                    if (this.states.size % 50000 == 0 && this.isDebug) {
                        console.log("VISITED STATES: " + this.states.size);
                        console.log("EVALUATED TRANSITIONS: " + this.transitions);
                        console.log("-------------------");
                    }
                }
            }
            if (this.invViolated(state)) {
                this.invariantViolated = true;
                this.counterExampleState = state;
                break;
            }
            if (nextStates.size == 0) {
                this.deadlockDetected = true;
                this.counterExampleState = state;
                break;
            }
        }
        this.printResult(this.states.size, this.transitions);
    }
    initCache(machine) {
        this.invariantDependency = this.invariantDependency.set("prog2", immutable.Set(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("prog1", immutable.Set(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("progress", immutable.Set(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("final_evt", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("prog2", immutable.Set(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
        this.guardDependency = this.guardDependency.set("prog1", immutable.Set(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
        this.guardDependency = this.guardDependency.set("progress", immutable.Set(["_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"]));
        this.guardDependency = this.guardDependency.set("final_evt", immutable.Set([]));
    }
    next() {
        switch (this.type) {
            case Type.BFS:
                return this.unvisitedStates.popFront();
            case Type.DFS:
                return this.unvisitedStates.popBack();
            case Type.MIXED:
                if (this.unvisitedStates.length % 2 == 0) {
                    return this.unvisitedStates.popFront();
                }
                else {
                    return this.unvisitedStates.popBack();
                }
            default:
                break;
        }
        return undefined;
    }
    generateNextStates(state) {
        let result = immutable.Set();
        if (this.isCaching) {
            let parentsGuard = state.guardCache;
            let newCache = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue = null;
            let dependentGuardsBoolean = true;
            let _trid_1;
            if (!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_progress");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_progress");
            }
            if (state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_progress();
            }
            else {
                _trid_1 = cachedValue;
            }
            newCache = newCache.set("_tr_progress", _trid_1);
            if (_trid_1) {
                let copiedState = state._copy();
                copiedState.progress();
                copiedState.parent = state;
                this.addCachedInfos("progress", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2;
            if (!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_prog1");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_prog1");
            }
            if (state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_prog1();
            }
            else {
                _trid_2 = cachedValue;
            }
            newCache = newCache.set("_tr_prog1", _trid_2);
            if (_trid_2) {
                let copiedState = state._copy();
                copiedState.prog1();
                copiedState.parent = state;
                this.addCachedInfos("prog1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3;
            if (!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_prog2");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_prog2");
            }
            if (state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_prog2();
            }
            else {
                _trid_3 = cachedValue;
            }
            newCache = newCache.set("_tr_prog2", _trid_3);
            if (_trid_3) {
                let copiedState = state._copy();
                copiedState.prog2();
                copiedState.parent = state;
                this.addCachedInfos("prog2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4;
            if (!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_final_evt");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_final_evt");
            }
            if (state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_final_evt();
            }
            else {
                _trid_4 = cachedValue;
            }
            newCache = newCache.set("_tr_final_evt", _trid_4);
            if (_trid_4) {
                let copiedState = state._copy();
                copiedState.final_evt();
                copiedState.parent = state;
                this.addCachedInfos("final_evt", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            state.guardCache = newCache;
        }
        else {
            if (state._tr_progress()) {
                let copiedState = state._copy();
                copiedState.progress();
                copiedState.parent = state;
                this.addCachedInfos("progress", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if (state._tr_prog1()) {
                let copiedState = state._copy();
                copiedState.prog1();
                copiedState.parent = state;
                this.addCachedInfos("prog1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if (state._tr_prog2()) {
                let copiedState = state._copy();
                copiedState.prog2();
                copiedState.parent = state;
                this.addCachedInfos("prog2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if (state._tr_final_evt()) {
                let copiedState = state._copy();
                copiedState.final_evt();
                copiedState.parent = state;
                this.addCachedInfos("final_evt", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
        }
        return result;
    }
    invViolated(state) {
        if (!(this.isCaching) || state.dependentInvariant.has("_check_inv_1")) {
            if (!state._check_inv_1()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
        }
        if (!(this.isCaching) || state.dependentInvariant.has("_check_inv_2")) {
            if (!state._check_inv_2()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                return true;
            }
        }
        if (!(this.isCaching) || state.dependentInvariant.has("_check_inv_3")) {
            if (!state._check_inv_3()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                return true;
            }
        }
        if (!(this.isCaching) || state.dependentInvariant.has("_check_inv_4")) {
            if (!state._check_inv_4()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                return true;
            }
        }
        if (!(this.isCaching) || state.dependentInvariant.has("_check_inv_5")) {
            if (!state._check_inv_5()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                return true;
            }
        }
        if (!(this.isCaching) || state.dependentInvariant.has("_check_inv_6")) {
            if (!state._check_inv_6()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                return true;
            }
        }
        return false;
    }
    addCachedInfos(operation, state, copiedState) {
        if (this.isCaching) {
            copiedState.dependentInvariant = this.invariantDependency.get(operation);
            copiedState.dependentGuard = this.guardDependency.get(operation);
        }
        copiedState.stateAccessedVia = operation;
    }
    printResult(states, transitions) {
        if (this.invariantViolated || this.deadlockDetected) {
            if (this.deadlockDetected) {
                console.log("DEADLOCK DETECTED");
            }
            else {
                console.log("INVARIANT VIOLATED");
            }
            console.log("COUNTER EXAMPLE TRACE: ");
            let sb = '';
            while (this.counterExampleState != null) {
                sb = this.counterExampleState + '\n' + sb;
                if (this.counterExampleState.stateAccessedVia != null) {
                    sb = this.counterExampleState.stateAccessedVia + sb;
                }
                sb = '\n\n' + sb;
                this.counterExampleState = this.counterExampleState.parent;
            }
            console.log(sb);
        }
        else {
            console.log("MODEL CHECKING SUCCESSFUL");
        }
        console.log("Number of States: " + this.states.size);
        console.log("Number of Transitions: " + this.transitions);
    }
}
let args = process.argv;
if (args.length > 5) {
    console.log("Expecting 3 command-line arguments: STRATEGY CACHING DEBUG");
    process.exit(-1);
}
let type = Type.MIXED;
let threads = 0;
let isCaching = false;
let isDebug = false;
if (args.length > 2) {
    if ("mixed" === args[2]) {
        type = Type.MIXED;
    }
    else if ("bf" === args[2]) {
        type = Type.BFS;
    }
    else if ("df" === args[2]) {
        type = Type.DFS;
    }
    else {
        console.log("Value for command-line argument STRATEGY is wrong.");
        console.log("Expecting mixed, bf or df.");
        process.exit(-1);
    }
}
if (args.length > 3) {
    try {
        isCaching = JSON.parse(args[3].toLowerCase());
    }
    catch (e) {
        console.log("Value for command-line argument CACHING is not a boolean.");
        process.exit(-1);
    }
}
if (args.length > 4) {
    try {
        isDebug = JSON.parse(args[4].toLowerCase());
    }
    catch (e) {
        console.log("Value for command-line argument DEBUG is not a boolean.");
        process.exit(-1);
    }
}
let modelchecker = new ModelChecker(type, isCaching, isDebug);
modelchecker.modelCheck();
