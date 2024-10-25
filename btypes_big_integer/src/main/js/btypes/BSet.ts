import {BBoolean} from "./BBoolean.js";
import {BInteger} from "./BInteger.js";
import {BObject} from "./BObject.js";
import {BRelation} from "./BRelation.js";
import {BString} from "./BString.js";
import {BStruct} from "./BStruct.js";
import * as immutable from "../immutable/dist/immutable.es.js";

export class BSet<T extends BObject> implements BObject{

	set: immutable.Set<T>;

	constructor(...args: any[]) {
		if (args.length == 1 && args[0] instanceof immutable.Set) {
			this.set = <immutable.Set<T>> args[0];
		} else {
			this.set = immutable.Set();
			for(let x of args) {
				this.set = this.set.add(x)
			}
		}
	}

	/* Make this class iterable */
	public [Symbol.iterator]() {
		return this.set[Symbol.iterator]();
	}

	toString(): string {
		let sb: string = "{";
		this.set.forEach((element: T) => {
			if(sb.length >1) {
				sb += ", ";
			}
			sb += element.toString();
		});
		sb += "}"
		return sb;
	}

	union(other: BSet<T>): BSet<T> {
		let result = BSet.immutableSetUnion(this.set, other.set);
		return new BSet(result)
	}

    unionForSets<K extends BObject>(): BSet<K> {
        if (this.set.isEmpty()) {
            return new BSet<K>();
        } else {
            return this.set.reduce(
                (a: BSet<K>, e: BSet<K>) => a.union(e),
                new BSet<K>()
            );
        }
    }

    unionForRelations<T1 extends BObject, T2 extends BObject>(): BRelation<T1, T2> {
        if (this.set.isEmpty()) {
            return new BRelation<T1, T2>();
        } else {
            return this.set.reduce(
                (a: BRelation<T1, T2>, e: BRelation<T1, T2>) => a.union(e),
                new BRelation<T1, T2>()
            );
        }
    }

	static immutableSetUnion<R extends BObject>(s1: immutable.Set<R>, s2: immutable.Set<R>): immutable.Set<R>{
		return s1.union(s2);
	}

	static immutableSetDifference<R extends BObject>(s1: immutable.Set<R>, s2: immutable.Set<R>): immutable.Set<R> {
		return s1.subtract(s2);
	}

	static immutableSetIntersection<R extends BObject>(s1: immutable.Set<R>, s2: immutable.Set<R>): immutable.Set<R> {
		return s1.intersect(s2);
	}

	static immutableMapUnion<S extends BObject, T extends BObject>(m1: immutable.Map<S, immutable.Set<T>>,
																   m2: immutable.Map<S, immutable.Set<T>>): immutable.Map<S, immutable.Set<T>> {
		let result: immutable.Map<S, immutable.Set<T>> = m2;
		outer_loop:
		for (let current_element of m1.keys()) {
			for (let result_element of result.keys()) {
				if (current_element.equals(result_element)) {
					let result_set = result.get(result_element);
					let current_set = m1.get(current_element);
					result = result.set(result_element,
						BSet.immutableSetUnion(result_set !=null ? result_set : immutable.Set<T>(),
											   current_set !=null ? current_set: immutable.Set<T>()));
					continue outer_loop;
				}
			}
			result = result.set(current_element, <immutable.Set<T>><unknown> m1.get(current_element))
		}
		return result;
	}

	static immutableMapIntersection<S extends BObject, T extends BObject>(m1: immutable.Map<S, immutable.Set<T>>,
																		  m2: immutable.Map<S, immutable.Set<T>>): immutable.Map<S, immutable.Set<T>> {
		let result = immutable.Map<S, immutable.Set<T>>();
		elem_loop:
		for (let result_element of m2.keys()) {
			for (let current_element of m1.keys()) {
				if (current_element.equals(result_element)) {
					let result_set = m2.get(result_element);
					let current_set = m1.get(current_element);
					result = result.set(result_element,
						BSet.immutableSetIntersection(result_set !=null ? result_set : immutable.Set(),
												      current_set !=null ? current_set: immutable.Set()));
					continue elem_loop;
				}
			}
			result.delete(result_element);
		}
		return result;
	}

	intersect(other: BSet<T>): BSet<T> {
		let result = BSet.immutableSetIntersection(this.set, other.set);
		return new BSet(result)
	}

    intersectForSets<K extends BObject>(): BSet<K> {
        if (this.set.isEmpty()) {
            return new BSet<K>();
        } else {
            return this.set.reduce(
                (a: BSet<K>, e: BSet<K>) => a.intersect(e)
            );
        }
    }

    intersectForRelations<T1 extends BObject, T2 extends BObject>(): BRelation<T1, T2> {
        if (this.set.isEmpty()) {
            return new BRelation<T1, T2>();
        } else {
            return this.set.reduce(
                (a: BRelation<T1, T2>, e: BRelation<T1, T2>) => a.intersect(e)
            );
        }
    }

	difference(other: BSet<T>): BSet<T> {
		let set = BSet.immutableSetDifference(this.set, other.set)
		return new BSet<T>(set);
	}

	card(): BInteger {
		return new BInteger(this.set.size);
	}

	size(): BInteger {
		return new BInteger(this.set.size);
	}

	elementOf(obj: T): BBoolean {
		return new BBoolean(this.set.has(obj));
	}

	notElementOf(obj: T): BBoolean {
		return new BBoolean(!this.set.has(obj));
	}

	subset(other: BSet<T>): BBoolean {
		this_set_loop:
		for (let elem of this.set) {
			for (let other_elem of other.set) {
				if (other_elem.equals(elem)) {
					continue this_set_loop;
				}
			}
			return new BBoolean(false);
		}
		return new BBoolean(true);
	}

	notSubset(other: BSet<T>): BBoolean {
		this_set_loop:
			for (let elem of this.set) {
				for (let other_elem of other.set) {
					if (other_elem.equals(elem)) {
						continue this_set_loop;
					}
				}
				return new BBoolean(true);
			}
		return new BBoolean(false);
	}

	strictSubset(other: BSet<T>): BBoolean {
		return this.size().less(other.size()).and(this.subset(other));
	}

	strictNotSubset(other: BSet<T>): BBoolean {
		return this.size().equal(other.size()).and(this.notSubset(other));
	}

	contains(other: T): boolean {
		return other in this.set;
	}

	containsAll(other: BSet<T>): boolean {
		for (let o of other.set) {
			if (!(o in this.set)) {
				return false
			}
		}
		return true
	}

	isEmpty(): boolean {
		return this.set.size === 0
	}

	equals(other: any): boolean {
        if (!(other instanceof BSet)) {
            return false;
        }
        return this.set.equals(other.set);
	}

	equal(other: any): BBoolean {
	    return new BBoolean(this.equals(other));
	}

	unequal(other: any): BBoolean {
		return new BBoolean(!this.equals(other));
	}

	nondeterminism(): T {
		let values = []
		for (let item of this.set) {
			values.push(item)
		}
		return values[Math.floor(Math.random() * values.length)]
	}

	min(): T {
		return this.set.reduce((a: T, v: T) => {if(a<v){return a} return v});
	}

	max(): T {
		return this.set.reduce((a: T, v: T) => {if(a>v){return a} return v});
	}

	pow(): BSet<BSet<T>> {
		let result = new BSet<BSet<T>>()
		let start = new BSet<T>()
		let queue = [start]
		result = result.union(new BSet<BSet<T>>(start))
		while (queue.length != 0) {
			let currentSet = <BSet<T>> queue.pop()
			for (let element of this.set) {
				let nextSet = currentSet.union(new BSet<T>(element))
				let previousSize = result.size()
				result = result.union(new BSet<BSet<T>>(nextSet))
				if (previousSize < result.size()) {
					queue.push(nextSet)
				}
			}
		}

		return result
	}

	pow1(): BSet<BSet<T>> {
		return this.pow().difference(new BSet(new BSet()))
	}

	// Only finite subsets are supported so fin = pow
	fin(): BSet<BSet<T>> {
		return this.pow();
	}

	fin1(): BSet<BSet<T>> {
		return this.pow1();
	}

	subsetOfInteger(): BBoolean {
		for (let element of this.set) {
			if (element ! instanceof BInteger) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	strictSubsetOfInteger(): BBoolean {
		return this.subsetOfInteger();
	}

	notSubsetOfInteger(): BBoolean {
		return this.subsetOfInteger().not();
	}

	notStrictSubsetOfInteger(): BBoolean {
		return this.strictSubsetOfInteger().not();
	}

	subsetOfNatural(): BBoolean {
		for (let element of this.set) {
			if (!(element instanceof BInteger && element.isNatural().booleanValue())) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true)
	}

	strictSubsetOfNatural(): BBoolean {
		return this.subsetOfNatural()
	}

	notSubsetOfNatural(): BBoolean {
		return this.subsetOfNatural().not()
	}

	notStrictSubsetOfNatural(): BBoolean {
		return this.strictSubsetOfNatural().not()
	}

	subsetOfNatural1(): BBoolean {
		for (let element of this.set) {
			if (!(element instanceof BInteger && element.isNatural1().booleanValue())) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true)
	}

	subsetOfString(): BBoolean {
		for (let element of this.set) {
			if (!(element instanceof BString)) {
				return new BBoolean(false)
			}
		}
		return new BBoolean(true)
	}

	strictSubsetOfString(): BBoolean {
		return this.subsetOfString()
	}

	notSubsetOfString(): BBoolean {
		return this.subsetOfString().not()
	}

	notStrictSubsetOfString(): BBoolean {
		return this.strictSubsetOfString().not()
	}

	subsetOfStruct(): BBoolean {
		for (let element of this.set) {
			if (!(element instanceof BStruct)) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	strictSubsetOfStruct(): BBoolean {
		return this.subsetOfStruct()
	}

	notSubsetOfStruct(): BBoolean {
		return this.subsetOfStruct().not()
	}

	notStrictSubsetOfStruct(): BBoolean {
		return this.strictSubsetOfStruct().not()
	}

	equalInteger(): BBoolean {
		return new BBoolean(false)
	}

	unequalInteger(): BBoolean {
			return new BBoolean(true)
	}

	equalNatural(): BBoolean {
		return new BBoolean(false)
	}

	unequalNatural(): BBoolean {
		return new BBoolean(true)
	}

	equalNatural1(): BBoolean {
		return new BBoolean(false)
	}

	unequalNatural1(): BBoolean {
		return new BBoolean(true)
	}

	equalString(): BBoolean {
		return new BBoolean(false)
	}

	unequalString(): BBoolean {
		return new BBoolean(true)
	}

	equalStruct(): BBoolean {
		return new BBoolean(false)
	}

	unequalStruct(): BBoolean {
		return new BBoolean(true)
	}

	getSet() : immutable.Set<T> {
		return this.set
	}

	static interval(a: BInteger, b: BInteger): BSet<BInteger> {
        if (b.less(a).booleanValue()) {
            return new BSet();
        }

        let persistentSet =  immutable.Set();
        for(let i = a; i.lessEqual(b).booleanValue(); i = i.plus(new BInteger(1))) {
            persistentSet = persistentSet.add(i);
        }

        return new BSet(persistentSet);
	}


	hashCode(): number {
		return this.set.hashCode()
	}
}
