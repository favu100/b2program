import { BBoolean } from "./BBoolean.js";
import { BInteger } from "./BInteger.js";
import { BRelation } from "./BRelation.js";
import { BString } from "./BString.js";
import { BStruct } from "./BStruct.js";
import * as immutable from "../immutable/dist/immutable.es.js";
export class BSet {
    constructor(...args) {
        if (args.length == 1 && args[0] instanceof immutable.Set) {
            this.set = args[0];
        }
        else {
            this.set = immutable.Set();
            for (let x of args) {
                this.set = this.set.add(x);
            }
        }
    }
    /* Make this class iterable */
    [Symbol.iterator]() {
        return this.set[Symbol.iterator]();
    }
    toString() {
        let sb = "{";
        this.set.forEach((element) => {
            if (sb.length > 1) {
                sb += ", ";
            }
            sb += element.toString();
        });
        sb += "}";
        return sb;
    }
    union(other) {
        let result = BSet.immutableSetUnion(this.set, other.set);
        return new BSet(result);
    }
    unionForSets() {
        if (this.set.isEmpty()) {
            return new BSet();
        }
        else {
            return this.set.reduce((a, e) => a.union(e), new BSet());
        }
    }
    unionForRelations() {
        if (this.set.isEmpty()) {
            return new BRelation();
        }
        else {
            return this.set.reduce((a, e) => a.union(e), new BRelation());
        }
    }
    static immutableSetUnion(s1, s2) {
        return s1.union(s2);
    }
    static immutableSetDifference(s1, s2) {
        return s1.subtract(s2);
    }
    static immutableSetIntersection(s1, s2) {
        return s1.intersect(s2);
    }
    static immutableMapUnion(m1, m2) {
        let result = m2;
        outer_loop: for (let current_element of m1.keys()) {
            for (let result_element of result.keys()) {
                if (current_element.equals(result_element)) {
                    let result_set = result.get(result_element);
                    let current_set = m1.get(current_element);
                    result = result.set(result_element, BSet.immutableSetUnion(result_set != null ? result_set : immutable.Set(), current_set != null ? current_set : immutable.Set()));
                    continue outer_loop;
                }
            }
            result = result.set(current_element, m1.get(current_element));
        }
        return result;
    }
    static immutableMapIntersection(m1, m2) {
        let result = immutable.Map();
        elem_loop: for (let result_element of m2.keys()) {
            for (let current_element of m1.keys()) {
                if (current_element.equals(result_element)) {
                    let result_set = m2.get(result_element);
                    let current_set = m1.get(current_element);
                    result = result.set(result_element, BSet.immutableSetIntersection(result_set != null ? result_set : immutable.Set(), current_set != null ? current_set : immutable.Set()));
                    continue elem_loop;
                }
            }
            result.delete(result_element);
        }
        return result;
    }
    intersect(other) {
        let result = BSet.immutableSetIntersection(this.set, other.set);
        return new BSet(result);
    }
    intersectForSets() {
        if (this.set.isEmpty()) {
            return new BSet();
        }
        else {
            return this.set.reduce((a, e) => a.intersect(e));
        }
    }
    intersectForRelations() {
        if (this.set.isEmpty()) {
            return new BRelation();
        }
        else {
            return this.set.reduce((a, e) => a.intersect(e));
        }
    }
    difference(other) {
        let set = BSet.immutableSetDifference(this.set, other.set);
        return new BSet(set);
    }
    card() {
        return new BInteger(this.set.size);
    }
    size() {
        return new BInteger(this.set.size);
    }
    elementOf(obj) {
        return new BBoolean(this.set.has(obj));
    }
    notElementOf(obj) {
        return new BBoolean(!this.set.has(obj));
    }
    subset(other) {
        this_set_loop: for (let elem of this.set) {
            for (let other_elem of other.set) {
                if (other_elem.equals(elem)) {
                    continue this_set_loop;
                }
            }
            return new BBoolean(false);
        }
        return new BBoolean(true);
    }
    notSubset(other) {
        this_set_loop: for (let elem of this.set) {
            for (let other_elem of other.set) {
                if (other_elem.equals(elem)) {
                    continue this_set_loop;
                }
            }
            return new BBoolean(true);
        }
        return new BBoolean(false);
    }
    strictSubset(other) {
        return this.size().less(other.size()).and(this.subset(other));
    }
    strictNotSubset(other) {
        return this.size().equal(other.size()).and(this.notSubset(other));
    }
    contains(other) {
        return other.toString() in this.set;
    }
    containsAll(other) {
        for (let o of other.set) {
            if (!(o in this.set)) {
                return false;
            }
        }
        return true;
    }
    isEmpty() {
        return this.set.size === 0;
    }
    equals(other) {
        if (!(other instanceof BSet)) {
            return false;
        }
        return this.set.equals(other.set);
    }
    equal(other) {
        return new BBoolean(this.equals(other));
    }
    unequal(other) {
        return new BBoolean(!this.equals(other));
    }
    nondeterminism() {
        let values = [];
        for (let item of this.set) {
            values.push(item);
        }
        return values[Math.floor(Math.random() * values.length)];
    }
    min() {
        return this.set.reduce((a, v) => { if (a < v) {
            return a;
        } return v; });
    }
    max() {
        return this.set.reduce((a, v) => { if (a > v) {
            return a;
        } return v; });
    }
    pow() {
        let result = new BSet();
        let start = new BSet();
        let queue = [start];
        result = result.union(new BSet(start));
        while (queue.length != 0) {
            let currentSet = queue.pop();
            for (let element of this.set) {
                let nextSet = currentSet.union(new BSet(element));
                let previousSize = result.size();
                result = result.union(new BSet(nextSet));
                if (previousSize < result.size()) {
                    queue.push(nextSet);
                }
            }
        }
        return result;
    }
    pow1() {
        return this.pow().difference(new BSet(new BSet()));
    }
    // Only finite subsets are supported so fin = pow
    fin() {
        return this.pow();
    }
    fin1() {
        return this.pow1();
    }
    subsetOfInteger() {
        for (let element of this.set) {
            if (element instanceof BInteger) {
                return false;
            }
        }
        return true;
    }
    strictSubsetOfInteger() {
        return this.subsetOfInteger();
    }
    notSubsetOfInteger() {
        return !this.subsetOfInteger();
    }
    notStrictSubsetOfInteger() {
        return !this.strictSubsetOfInteger();
    }
    subsetOfNatural() {
        for (let element of this.set) {
            if (!(element instanceof BInteger && element.isNatural().booleanValue())) {
                return false;
            }
        }
        return true;
    }
    strictSubsetOfNatural() {
        return this.subsetOfNatural();
    }
    notSubsetOfNatural() {
        return !this.subsetOfNatural();
    }
    notStrictSubsetOfNatural() {
        return !this.strictSubsetOfNatural();
    }
    subsetOfNatural1() {
        for (let element of this.set) {
            if (!(element instanceof BInteger && element.isNatural1().booleanValue())) {
                return false;
            }
        }
        return true;
    }
    subsetOfString() {
        for (let element of this.set) {
            if (!(element instanceof BString)) {
                return false;
            }
        }
        return true;
    }
    strictSubsetOfString() {
        return this.subsetOfString();
    }
    notSubsetOfString() {
        return !this.subsetOfString();
    }
    notStrictSubsetOfString() {
        return !this.strictSubsetOfString();
    }
    subsetOfStruct() {
        for (let element of this.set) {
            if (!(element instanceof BStruct)) {
                return false;
            }
        }
        return true;
    }
    strictSubsetOfStruct() {
        return this.subsetOfStruct();
    }
    notSubsetOfStruct() {
        return !this.subsetOfStruct();
    }
    notStrictSubsetOfStruct() {
        return !this.strictSubsetOfStruct();
    }
    equalInteger() {
        return new BBoolean(false);
    }
    unequalInteger() {
        return new BBoolean(true);
    }
    equalNatural() {
        return new BBoolean(false);
    }
    unequalNatural() {
        return new BBoolean(true);
    }
    equalNatural1() {
        return new BBoolean(false);
    }
    unequalNatural1() {
        return new BBoolean(true);
    }
    equalString() {
        return new BBoolean(false);
    }
    unequalString() {
        return new BBoolean(true);
    }
    equalStruct() {
        return new BBoolean(false);
    }
    unequalStruct() {
        return new BBoolean(true);
    }
    getSet() {
        return this.set;
    }
    static interval(a, b) {
        if (b.less(a).booleanValue()) {
            return new BSet();
        }
        let persistentSet = immutable.Set();
        for (let i = a; i.lessEqual(b).booleanValue(); i = i.plus(new BInteger(1))) {
            persistentSet = persistentSet.add(i);
        }
        return new BSet(persistentSet);
    }
    hashCode() {
        return this.set.hashCode();
    }
}
