import {BBoolean} from "./BBoolean";
import {BInteger} from "./BInteger";
import {BObject} from "./BObject";
import {BRelation} from "./BRelation";
import {BString} from "./BString";
import {BStruct} from "./BStruct";

const {Set} = require('immutable')

export class BSet<T> implements BObject {

	set;

	constructor(...args: any[]) {
		if (args.length == 1 && args[0] instanceof Set) {
			this.set = args[0];
		} else {
			this.set = new Set(args);
		}
	}

	toString(): string {
		let sb: string = "{";
		this.set.forEach(element => {
			if(sb.length >1) {
				sb += ", ";
			}
			sb += element.toString();
		});
		sb += "}"
		return sb;
	}

	union(other: BSet<T> | null): BSet<T> {
		if (other == null) {
			if (this.set.size === 0) {
				return new BSet<T>()
			} else if (this.set.values().next() instanceof BSet) {
				return this.set.reduce(function (a, e) {
					a.union(e)
				}, this, new BSet())
			} else if (this.set.values().next() instanceof BRelation) {
				return this.set.reduce(function (a, e) {
					a.union(e)
				}, new BRelation());
			}
		}
		const new_set = this.set.union(other.set);
		return new BSet(new_set);
	}

	intersect(other: BSet<T> | null): BSet<T> {
		if (other == null) {
			if (this.set.length === 0) {
				return new BSet<T>()
			} else if (this.set.values.next() instanceof BSet) {
				return this.set.reduce(function (a, e) {
					a.intersect(e)
				}, this, new BSet())
			} else if (this.set.values.next() instanceof BRelation) {
				return this.set.reduce(function (a, e) {
					a.intersect(e)
				}, new BRelation());
			}
		}
		let new_set = this.set;
		const other_set = other.set;
		for (let elem of this.set) {
			if (elem ! in other_set) {
				new_set = new_set.delete(elem);
			}
		}
		return new BSet(new_set);
	}

	difference(other: BSet<T>): BSet<T> {
		var set = this.set;
		var other_set = other.set;
		set = set.subtract(other_set);

		return new BSet<T>(set);
	}

	card(): BInteger {
		return new BInteger(this.set.size);
	}

	size(): BInteger {
		return new BInteger(this.set.size);
	}

	elementOf(obj: T): BBoolean {
		return new BBoolean(obj in this.set);
	}

	notElementOf(self, obj): BBoolean {
		return new BBoolean(obj ! in this.set);
	}

	subset(other: BSet<T>): BBoolean {
		return new BBoolean(this.set.filter(elem => elem ! in other.set).size === 0);
	}

	notSubset(other: BSet<T>): BBoolean {
		return new BBoolean(this.set.filter(elem => elem ! in other.set).size > 0);
	}

	strictSubset(other: BSet<T>): BBoolean {
		return new BBoolean(other.size > this.set.size &&
			this.set.filter(elem => elem ! in other.set).size === 0);
	}

	strictNotSubset(other: BSet<T>): BBoolean {
		return new BBoolean(other.size() == this.size() &&
			!(this.set.filter(elem => elem ! in other.set).size > 0));
	}

	contains(other: T): boolean {
		return other in this.set;
	}

	containsAll(other: BSet<T>): boolean {
		for (let o of other.set) {
			if (o ! in this.set) {
				return false
			}
		}
		return true
	}

	isEmpty(): boolean {
		return this.set.size === 0
	}

	equal(other): boolean {
		if (other ! instanceof BSet) {
			return false;
		}
		return this.set === other.set
	}

	unequal(other): boolean {
		if (other ! instanceof BSet) {
			return true;
		}
		return this.set !== other.set
	}

	nondeterminism(self): T {
		let values = []
		for (let item of this.set) {
			values.push(item)
		}
		return values[Math.floor(Math.random() * values.length)]
	}

	min(): T {
		return Math.min.apply(null, this.set)
	}

	max(): T {
		return Math.max.apply(null, this.set)
	}

	pow(): BSet<BSet<T>> {
		let result = new BSet<BSet<T>>()
		let start = new BSet()
		let queue = [start]
		result = result.union(new BSet(start))
		while (!(queue.length == 0)) {
			let currentSet = queue.pop()
			for (let element of this.set) {
				let nextSet = currentSet.union(new BSet(element))
				let previousSize = result.size()
				result = result.union(new BSet(nextSet))
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

	subsetOfInteger(): boolean {
		for (let element of this.set) {
			if (element ! instanceof BInteger) {
				return false;
			}
		}
		return true;
	}

	strictSubsetOfInteger(): boolean {
		return this.subsetOfInteger();
	}

	notSubsetOfInteger(): boolean {
		return !this.subsetOfInteger();
	}

	notStrictSubsetOfInteger(): boolean {
		return !this.strictSubsetOfInteger();
	}

	subsetOfNatural(): boolean {
		for (let element of this.set) {
			if (!(element instanceof BInteger && element.isNatural().booleanValue())) {
				return false;
			}
		}
		return true
	}

	strictSubsetOfNatural(): boolean {
		return this.subsetOfNatural()
	}

	notSubsetOfNatural(): boolean {
		return !this.subsetOfNatural()
	}

	notStrictSubsetOfNatural(): boolean {
		return !this.strictSubsetOfNatural()
	}

	subsetOfNatural1(): boolean {
		for (let element of this.set) {
			if (!(element instanceof BInteger && element.isNatural1().booleanValue())) {
				return false;
			}
		}
		return true
	}

	subsetOfString(): boolean {
		for (let element of this.set) {
			if (element ! instanceof BString) {
				return false
			}
		}
		return true
	}

	strictSubsetOfString(): boolean {
		return this.subsetOfString()
	}

	notSubsetOfString(): boolean {
		return !this.subsetOfString()
	}

	notStrictSubsetOfString(): boolean {
		return !this.strictSubsetOfString()
	}

	subsetOfStruct(): boolean {
		for (let element of this.set) {
			if (element !instanceof BStruct) {
				return false;
			}
		}
		return true;
	}

	strictSubsetOfStruct(): boolean {
		return this.subsetOfStruct()
	}

	notSubsetOfStruct(): boolean {
		return !this.subsetOfStruct()
	}

	notStrictSubsetOfStruct(): boolean {
		return !this.strictSubsetOfStruct()
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

	getSet() {
		return this.set
	}

	static interval(a: BInteger, b: BInteger): BSet<BInteger> {
		var range = Array(b.minus(a).intValue()).map(e => new BInteger(e))
		return new BSet(range);
	}
}
