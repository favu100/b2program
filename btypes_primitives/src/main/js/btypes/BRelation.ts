import {BTuple} from "./BTuple.js";
import {BSet} from "./BSet.js";
import {BInteger} from "./BInteger.js";
import {BBoolean} from "./BBoolean.js";
import {BString} from "./BString.js";
import {BStruct} from "./BStruct.js";
import {BObject} from "./BObject.js";

const {Map} = require("immutable");
const {Set} = require("immutable");
import * as immutable from "immutable";

export class BRelation<S extends BObject,T extends BObject> implements BObject {

	map: immutable.Map<S, immutable.Set<T>>;

	constructor(...args: any[]) {
		if (args.length === 0) {
			this.map = Map()
		} else if (args.length == 1 && args[0] instanceof immutable.Map) {
			this.map = args[0] as immutable.Map<S, immutable.Set<T>>
		} else {
			this.map = Map()
			for (let e of args) {
				let key = e.projection1()
				let value = e.projection2()
				let set = this.map.get(key)
				if (set == null) {
					set = immutable.Set()
				}
				set = set.add(value)
				this.map = this.map.set(key, set)
			}
		}
	}

	static fromSet<S extends BObject,T extends BObject>(set: BSet<BTuple<S, T>> ): BRelation<S,T> {
		let resultMap = Map();
		set.getSet().forEach(e => {
			let key: S = e.projection1();
			let value: T = e.projection2();
			let range: any = resultMap.get(key);
			if(range == null) {
				range = Set([value]);
				resultMap = resultMap.set(key, range);
			} else {
				range = range.add(value);
				resultMap = resultMap.set(key, range);
			}
		});
		return new BRelation<S,T>(resultMap);
	}

	equals(o: any): boolean {
		if (o == null || !(o instanceof BRelation))
			return false;

		return this.map.equals(o.map);
	}

	intersect(relation: BRelation<S, T>): BRelation<S,T>  {
		let otherMap: immutable.Map<S, immutable.Set<T>> = relation.map;
		let otherDomain = otherMap.keys();
		let thisDomain = Set(this.map.keys());
		let intersectionDomain = thisDomain.intersect(otherDomain);
		let differenceDomain  = thisDomain.subtract(otherDomain);
		let resultMap: immutable.Map<S, immutable.Set<T>> = this.map;

		intersectionDomain.forEach((domainElement: S) => {
			let thisRangeSet: immutable.Set<T> = <immutable.Set<T>> this.map.get(domainElement);
			let otherRangeSet = <immutable.Set<T>> otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, thisRangeSet.intersect(otherRangeSet));
		});

		differenceDomain.forEach((domainElement: S) => {
			resultMap = resultMap.set(domainElement, Set());
		});

		return new BRelation<S,T>(resultMap);
	}

	difference(relation: BRelation<S, T>): BRelation<S, T> {
		let otherMap: immutable.Map<S, immutable.Set<T>> = relation.map;
		let otherDomain = otherMap.keys();
		let thisDomain = Set(this.map.keys());
		let differenceDomain = thisDomain.subtract(otherDomain);
		let restDomain = thisDomain.subtract(differenceDomain);

		let resultMap: immutable.Map<S, immutable.Set<T>> = this.map;
		differenceDomain.forEach((domainElement: S) => {
			let thisRangeSet = <immutable.Set<T>> this.map.get(domainElement);
			let otherRangeSet = <immutable.Set<T>> otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, thisRangeSet.subtract(otherRangeSet));
		});

		restDomain.forEach((domainElement: S) => {
			resultMap = resultMap.set(domainElement, Set());
		});
		return new BRelation<S,T>(resultMap);
	}

	union(relation: BRelation<S, T>): BRelation<S, T> {
		let otherMap = relation.map;
		let otherDomain = Set(otherMap.keys());

		let resultMap = this.map;
        for (let domainElement of otherDomain) {
			let thisRangeSet = this.map.get(domainElement);
			let otherRangeSet = <immutable.Set<T>> otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, thisRangeSet != null? thisRangeSet.union(otherRangeSet) : otherRangeSet);
		}
		return new BRelation<S,T>(resultMap);
	}

	size(): number {
		let size: number = 0;
		let thisDomain = Set(this.map.keys());

		for(let domainElement of thisDomain) {
			let thisRangeSet = this.map.get(domainElement);
			if(thisRangeSet != null) {
				size += thisRangeSet.size;
			}
		}
		return size;
	}

	card(): BInteger {
		return new BInteger(this.size());
	}

	equal(o: BRelation<S, T>): BBoolean {
		return new BBoolean(this.equals(o));
	}

	unequal(o: BRelation<S, T>): BBoolean {
		return new BBoolean(!this.equals(o));
	}

	elementOf(object: BTuple<S, T>): BBoolean {
		let prj1: S = object.projection1();
		let prj2: T = object.projection2();

		if(!this.map.has(prj1)) {
			return new BBoolean(false);
		}

		let range = <immutable.Set<T>> this.map.get(prj1);

		return new BBoolean(range.has(prj2));
	}

	notElementOf(object: BTuple<S,T> ): BBoolean {
		let prj1: S = object.projection1();
		let prj2: T = object.projection2();

		if(!this.map.has(prj1)) {
			return new BBoolean(true);
		}

		let range = <immutable.Set<T>> this.map.get(prj1);

		return new BBoolean(!range.has(prj2));
	}

	relationImage(domain: BSet<S> ): BSet<T> {
		let resultSet = Set();
		for (let this_domain_elem of this.map.keys()){
			for(let other_domain_elem of domain.set) {
				if(other_domain_elem.equals(this_domain_elem)) {
					let thisRangeSet: immutable.Set<T> = <immutable.Set<T>> this.map.get(this_domain_elem);
					if(thisRangeSet != null) {
						resultSet = BSet.immutableSetUnion(resultSet, thisRangeSet);
					}
				}
			}
		}
		return new BSet<T>(resultSet);
	}


	functionCall(arg: S): T {
		let range = undefined;
		for (let elem of this.map.keys()) {
			if(elem.equals(arg)) {
				range = this.map.get(elem);
			}
		}
		if(range == null) {
			throw new Error("Argument is not in the domain of this relation");
		}

		for (let element of range) {
			return element;
		}
		throw new Error("Argument is not in the domain of this relation");
	}

	pow(): BSet<BRelation<S,T>> {
		let thisMap = this.map;
		let thisDomain = Set(thisMap.keys());


		let result: BSet<BRelation<S,T>> = new BSet<BRelation<S,T>>();
		let start: BRelation<S,T> = new BRelation();
		let queue = [];
		queue.push(start);
		result = result.union(new BSet<BRelation<S,T>>(start));
		while(queue.length !== 0) {
			let currentSet: BRelation<S,T> = <BRelation<S, T>>queue.pop();

			for(let domainElement of thisDomain) {
				let range = <immutable.Set<T>> thisMap.get(domainElement);
				range.forEach(rangeElement => {
					let nextRelation: BRelation<S,T>  = currentSet.union(BRelation.fromSet(new BSet(new BTuple<S,T>(domainElement, rangeElement))));
					let previousSize: number = result.size().intValue();
					result = result.union(new BSet<BRelation<S,T>>(nextRelation));
					if(previousSize < result.size().intValue()) {
						queue.push(nextRelation);
					}
				});
			}
		}
		return result;
	}
	
	pow1(): BSet<BRelation<S,T>> {
		return this.pow().difference(new BSet<BRelation<S,T>>(new BRelation<S,T>()));
	}

	fin(): BSet<BRelation<S,T>> {
		return this.pow();
	}

	fin1(): BSet<BRelation<S,T>> {
		return this.pow1();
	}
	
	domain(): BSet<S> {
		let resultSet = Set(this.map.keys());
		for(let domainElement of this.map.keys()) {
			let range = <immutable.Set<T>> this.map.get(domainElement)
			if(range.size === 0) {
				resultSet = resultSet.remove(domainElement);
			}
		}
		return new BSet<S>(resultSet);
	}

	range(): BSet<T> {
		let set = Set.union(this.map.values());
		return new BSet<T>(set);
	}

	inverse(): BRelation<T,S> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let keys = Set(thisMap.keys());

		let resultMap: immutable.Map<T, immutable.Set<S>> = immutable.Map<T, immutable.Set<S>>();
		for(let domainElement of keys) {
			let range: immutable.Set<T> = <immutable.Set<T>> this.map.get(domainElement)
			range.forEach((rangeElement: T) => {
				let currentRange = resultMap.get(rangeElement);
				if(currentRange == null) {
					currentRange = immutable.Set();
				}
				currentRange = currentRange.union(immutable.Set([domainElement]));
				resultMap = resultMap.set(rangeElement, currentRange);
			});
		}
		return new BRelation<T, S>(resultMap);
	}

	domainRestriction(arg: BSet<S>): BRelation<S,T> {
		let resultMap = this.map;
		outer_loop:
		for(let obj of resultMap.keys()) {
			for(let obj2 of arg.set) {
				if(obj2.equals(obj)){
					continue outer_loop;
				}
			}
			resultMap = resultMap.delete(obj);
		}
		return new BRelation<S,T>(resultMap);
	}
	
	domainSubstraction(arg: BSet<S>): BRelation<S,T> {
		let resultMap = this.map;
		for(let obj of resultMap.keys()) {
			for(let obj2 of arg.set) {
				if(obj2.equals(obj)){
					resultMap = resultMap.delete(obj);
					break;
				}
			}
		}
		return new BRelation<S,T>(resultMap);
	}
	
	rangeRestriction(arg: BSet<T>): BRelation<S,T> {
		let otherSet: immutable.Set<T> = arg.getSet();
		let thisDomain = Set(this.map.keys());

		let resultMap = this.map
		for(let domainElement of thisDomain) {
			let thisRangeSet = <immutable.Set<T>> this.map.get(domainElement);
			resultMap = resultMap.set(domainElement, BSet.immutableSetIntersection(thisRangeSet, otherSet));
		}
		return new BRelation<S, T>(resultMap);
	}

	rangeSubstraction(arg: BSet<T>): BRelation<S, T> {
		let otherSet = arg.getSet();
		let thisDomain = Set(this.map.keys());

		let resultMap = this.map
		for(let domainElement of thisDomain) {
			let thisRangeSet = <immutable.Set<T>> this.map.get(domainElement);
			resultMap = resultMap.set(domainElement, BSet.immutableSetDifference(thisRangeSet, otherSet));
		}
		return new BRelation<S, T>(resultMap);
	}
	
	override(arg: BRelation<S,T>): BRelation<S,T> {
		let otherMap = arg.map;

		let otherDomain = Set(otherMap.keys());

		let resultMap = this.map;
		outer_loop:
		for(let domainElement of otherDomain) {
			for(let thisDomainElement of resultMap.keys()) {
				if(thisDomainElement.equals(domainElement)) {
					let range: immutable.Set<T> = <immutable.Set<T>> otherMap.get(domainElement);
					resultMap = resultMap.set(thisDomainElement, range);
					continue outer_loop;
				}
			}
			resultMap = resultMap.set(domainElement, <immutable.Set<T>> otherMap.get(domainElement));
		}

		return new BRelation<S, T>(resultMap);
	}
	
	first(): T {
		return this.functionCall(<S><unknown>new BInteger(1));
	}
	
	last(): T {
		return this.functionCall(<S><unknown>this.card());
	}
	
	reverse(): BRelation<S,T> {
		let size: BInteger = this.card();
		let resultMap: Map<S, Set<T>> = Map()
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let rangeElement: T = this.functionCall(<S><unknown>size.minus(i).succ());
			resultMap = resultMap.set(<S><unknown>i, Set([rangeElement]));
		}
		return new BRelation<S, T>(resultMap);
	}

	front(): BRelation<S,T> {
		return this.domainSubstraction(new BSet(this.card()));
	}
	
	tail(): BRelation<S,T> {
		let size: BInteger = this.card()
		let resultMap: Map<S, Set<T>> = Map()
		for(let i: BInteger = new BInteger(2); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let rangeElement: T = this.functionCall(<S><unknown>i);
			resultMap = resultMap.set(<S><unknown>i.pred(),Set([rangeElement]));
		}
		return new BRelation<S, T>(resultMap);
	}
	
	take(n: BInteger): BRelation<S,T> {
		let size: BInteger = this.card();
		if(n.greaterEqual(size).booleanValue()) {
			return new BRelation<S, T>(this.map);
		}
		let resultMap = this.map
		//Remove sets with index greater than n
		for(let i: BInteger = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
			for(let index of resultMap.keys()) {
				if(index.equals(i)) {
					resultMap = resultMap.delete(index);
					break;
				}
			}

		}
		return new BRelation<S, T>(resultMap);
	}
	
	drop(n: BInteger): BRelation<S,T> {
		let size: BInteger = this.card();
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let resultMap: immutable.Map<S, immutable.Set<T>> = Map();
		for(let i: BInteger = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let currentSet = thisMap.get(<S><unknown>i);
			resultMap = resultMap.set(<S><unknown>i.minus(n), <immutable.Set<T>> currentSet);
		}
		return new BRelation<S, T>(resultMap);
	}
	
	concat(arg: BRelation<S,T>): BRelation<S,T> {
		let resultMap = this.map
		let otherMap = arg.map;
		let size: BInteger = this.card();
		for(let i: BInteger = new BInteger(1); i.lessEqual(arg.card()).booleanValue(); i = i.succ()) {
			resultMap = resultMap.set(<S><unknown>size.plus(i), <immutable.Set<T>> otherMap.get(<S><unknown>i));
		}
		return new BRelation<S, T>(resultMap);
	}
	
	conc<R extends BObject,A extends BObject>(): BRelation<R,A> {
		let result: BRelation<R,A> = new BRelation<R,A>();
		let size: BInteger = this.card();
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			result = result.concat(<BRelation<R, A>><unknown>this.functionCall(<S><unknown>i));
		}
		return result;
	}
	
	append(arg: T): BRelation<S,T> {
		let resultMap = this.map
		resultMap = resultMap.set(<S><unknown>this.card().succ(), Set([arg]));
		return new BRelation<S, T>(resultMap);
	}
	
	prepend(arg: T): BRelation<S,T> {
		let resultMap: immutable.Map<S, immutable.Set<T>> = Map()
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let size: BInteger = this.card()
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			resultMap = resultMap.set(<S><unknown>i.succ(), <immutable.Set<T>> thisMap.get(<S><unknown>i));
		}
		resultMap = resultMap.set(<S><unknown>new BInteger(1), Set([arg]));
		return new BRelation<S, T>(resultMap);
	}

	directProduct<R extends BObject>(arg: BRelation<S,R>): BRelation<S,BTuple<T,R>> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let thisDomain = immutable.Set(thisMap.keys());
		let otherMap = arg.map;

		let resultMap: Map<S, Set<T>> = Map()
		for(let domainElement of thisDomain) {
			let thisRange: immutable.Set<T> = <immutable.Set<T>> this.map.get(domainElement)
			let otherRange = otherMap.get(domainElement);
			if(otherRange == undefined) {
				continue;
			}
			let resultRange = Set();
			thisRange.forEach(lhs => {
				otherRange!.forEach(rhs => {
					resultRange = Set.union([resultRange, Set([new BTuple<T,R>(lhs, rhs)])]);
				});
			});
			resultMap = resultMap.set(domainElement, resultRange);
		}
		return new BRelation<S, BTuple<T, R>>(resultMap);
	}
	
	parallelProduct<R extends BObject,A extends BObject>(arg: BRelation<R,A>): BRelation<BTuple<S,R>,BTuple<T,A>> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let thisDomain = Set(thisMap.keys());

		let otherMap: immutable.Map<R, immutable.Set<A>> = arg.map;
		let otherDomain = Set(otherMap.keys());

		let resultMap: immutable.Map<S, immutable.Set<T>> = Map()

		for(let domainElementThis of thisDomain) {
			for(let domainElementOther of otherDomain) {
				let thisRange: immutable.Set<T> = <immutable.Set<T>> thisMap.get(domainElementThis);
				let otherRange: immutable.Set<A> = <immutable.Set<A>> otherMap.get(domainElementOther);

				let resultRange = immutable.Set();
				thisRange.forEach(lhs => {
					otherRange.forEach(rhs => {
						resultRange = resultRange.union(immutable.Set([new BTuple<T,A>(lhs, rhs)]));
					});
				});
				let tuple: BTuple<S,R> = new BTuple<S,R>(domainElementThis, domainElementOther);
				resultMap = resultMap.set(<S><unknown>tuple, resultRange);
			}
		}
		return new BRelation<BTuple<S, R>, BTuple<T, A>>(resultMap);
	}

	
	composition<R extends BObject>(arg: BRelation<T,R>): BRelation<S,R> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let otherMap = arg.map;

		let resultMap: immutable.Map<S, immutable.Set<R>> = Map()

		for(let domainElement of this.map.keys()) {
			let range: immutable.Set<T> = <immutable.Set<T>> this.map.get(domainElement)

			let set: immutable.Set<R> = immutable.Set<R>();
			range.forEach((rangeElement: T) => {
				let union_element = otherMap.get(rangeElement)
				if (union_element == null) {
					return;
				}
				set = set.union(<immutable.Set<R>> union_element);
			});
			resultMap = resultMap.set(domainElement, set);
		}
		return new BRelation<S, R>(resultMap);
	}

	
	iterate(n: BInteger): BRelation<S,S> {
		let thisRelation: BRelation<S,S> = <BRelation<S,S>><unknown>this;
		let result: BRelation<S,S> = BRelation.identity(this.domain());
		for(let i: BInteger = new BInteger(1); i.lessEqual(n).booleanValue(); i = i.succ()) {
			result = result.union(result.composition(thisRelation));
		}
		return result;
	}

	
	closure(): BRelation<S,S> {
		let thisRelation: BRelation<S,S> = <BRelation<S, S>><unknown>this;
		let result: BRelation<S,S> = BRelation.identity(this.domain());
		let nextResult: BRelation<S,S> = result.composition(thisRelation);
		let lastResult: BRelation<S,S> = result;
		do {
			lastResult = result;
			result = result.union(nextResult);
			nextResult = result.composition(thisRelation);
		} while(!result.equal(lastResult).booleanValue());
		return result;
	}

	
	closure1(): BRelation<S,S> {
		let thisRelation: BRelation<S,S> = <BRelation<S,S>><unknown>this;
		let result: BRelation<S,S> = <BRelation<S,S>><unknown>this;
		let nextResult: BRelation<S,S> = result.composition(thisRelation);
 		let lastResult = null;
		do {
			lastResult = result;
			result = result.union(nextResult);
			nextResult = result.composition(thisRelation);
		} while(!result.equal(lastResult).booleanValue());
		return result;
	}


    static projection1<S extends BObject,T extends BObject>(arg1: BSet<S>, arg2: BSet<T>): BRelation<BTuple<S,T>, S> {
		let argSet1 = arg1.getSet();
		let argSet2 = arg2.getSet();

		let resultMap: Map<BTuple<BObject, BObject>, Set<BObject>> = Map()
		argSet1.forEach(e1 => {
			argSet2.forEach(e2 => {
				let tuple: BTuple<S,T> = new BTuple<S,T>(e1, e2);
				resultMap = resultMap.set(tuple, Set([e1]));
			});
		});
		return new BRelation<BTuple<S, T>, S>(resultMap);
	}


	static projection2<S extends BObject,T extends BObject>(arg1: BSet<S>, arg2: BSet<T>):  BRelation<BTuple<S,T>, T> {
		let argSet1 = arg1.getSet();
		let argSet2 = arg2.getSet();

		let resultMap: Map<BTuple<S, T>, Set<T>> = Map()
		argSet1.forEach(e1 => {
			argSet2.forEach(e2 => {

				let tuple: BTuple<S,T> = new BTuple<S,T>(e1, e2);
				resultMap = resultMap.set(tuple, Set([e2]));
			});
		});
		return new BRelation<BTuple<S, T>, T>(resultMap);
	}

	
	fnc(): BRelation<S,BSet<T>> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let domain = this.domain().getSet();

		let resultMap: Map<S, Set<BSet<T>>> = Map()
		domain.forEach(domainElement => {
			let range = thisMap.get(domainElement);
			let rangeSet: BSet<T> = new BSet<T>([range]);
			resultMap = resultMap.set(domainElement, Set([rangeSet]));
		});
		return new BRelation<S, BSet<T>>(resultMap);
	}

	rel<R extends BObject>(): BRelation<S,R> {
		let domain: immutable.Set<S> = this.domain().getSet();

		let resultMap: Map<S, Set<T>> = Map()
		domain.forEach(domainElement => {
			let range: BSet<R> = <BSet<R>><unknown>this.functionCall(domainElement);
			let rangeSet = range.getSet();
			resultMap = resultMap.set(domainElement, <Set<T>><unknown>rangeSet);
		});
		return new BRelation<S, R>(resultMap);
	}

    static identity<T extends BObject>(arg: BSet<T>):  BRelation<T,T> {
		let resultMap: Map<T, Set<T>> = Map()
		arg.getSet().forEach(e => {
			resultMap = resultMap.set(e, Set([e]));
		});
		return new BRelation<T, T>(resultMap);
	}


	static cartesianProduct<S extends BObject,T extends BObject>(arg1: BSet<S>, arg2: BSet<T>): BRelation<S,T> {
		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map()
		arg1.getSet().forEach(e1 => {
			resultMap = resultMap.set(e1, arg2.getSet());
		});
		return new BRelation<S, T>(resultMap);
	}

	
	nondeterminism(): BTuple<S,T> | null {
		let domain = Set(this.map.keys());
		let index: number = Math.floor(Math.random() * domain.size);
		let i: number = 0;
		let domainElement: S | undefined = undefined;
		for(let obj of domain) {
			if(i == index) {
				domainElement = obj;
				break;
			}
			i++;
		}

		if(domainElement == undefined) {
			return null;
		}

		let range = this.map.get(domainElement);
		if(range != null) {
			index = Math.floor(Math.random() * range.size);
			i = 0;
			range.forEach(obj => {
				if (i == index) {
					return new BTuple<S, T>(<S>domainElement, obj);
				}
				i++;
			});
		}
		return null;
	}

	isTotal(domain: BSet<S>): BBoolean {
		return new BBoolean(this.domain().equal(domain));
	}

	isTotalInteger(): BBoolean {
		return new BBoolean(false);
	}

	isTotalNatural(): BBoolean {
		return new BBoolean(false);
	}

	isTotalNatural1(): BBoolean {
		return new BBoolean(false);
	}

	isTotalString(): BBoolean {
		return new BBoolean(false);
	}

	isTotalStruct(): BBoolean {
		return new BBoolean(false);
	}

	isPartial(domain: BSet<S>): BBoolean {
		return this.domain().strictSubset(domain);
	}

	isPartialInteger(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	isPartialNatural(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BInteger && !(<BInteger>e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	isPartialNatural1(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BInteger && !(<BInteger>e).isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	isPartialString(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BString && !(<BString>e).isString().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	isPartialStruct(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BStruct && !(<BStruct>e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkDomain(domain: BSet<S>): BBoolean {
		return this.domain().subset(domain);
	}

	checkDomainInteger(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkDomainNatural(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BInteger && !(<BInteger>e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkDomainNatural1(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BInteger && !(<BInteger>e).isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkDomainString(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BString && !(<BString>e).isString().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkDomainStruct(): BBoolean {
		this.domain().getSet().forEach(e => {
			if(e instanceof BStruct && !(<BStruct>e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkRange(range: BSet<T>): BBoolean {
		return this.range().subset(range);
	}

	checkRangeInteger(): BBoolean {
		this.range().getSet().forEach(e => {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkRangeNatural(): BBoolean {
		this.range().getSet().forEach(e => {
			if(e instanceof BInteger && !(<BInteger> e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkRangeNatural1(): BBoolean {
		this.range().getSet().forEach(e => {
			if(e instanceof BInteger && !(<BInteger> e).isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkRangeString(): BBoolean {
		this.range().getSet().forEach(e => {
			if(e instanceof BString && !(<BString> e).isString().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	checkRangeStruct(): BBoolean {
		this.range().getSet().forEach(e => {
			if(e instanceof BStruct && !(<BStruct> e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	isRelation(): BBoolean {
		return new BBoolean(true);
	}

	isFunction(): BBoolean {
		this.domain().getSet().forEach(element => {
			let range = <immutable.Set<T>> this.map.get(element);
			if(range.size > 1) {
				return new BBoolean(false);
			}
		});
		return new BBoolean(true);
	}

	isSurjection(range: BSet<T>): BBoolean {
		return new BBoolean(this.range().equal(range));
	}

	isSurjectionInteger(): BBoolean {
		return new BBoolean(false);
	}

	isSurjectionNatural(): BBoolean {
		return new BBoolean(false);
	}

	isSurjectionNatural1(): BBoolean {
		return new BBoolean(false);
	}

	isSurjectionString(): BBoolean {
		return new BBoolean(false);
	}

	isSurjectionStruct(): BBoolean {
		return new BBoolean(false);
	}

	
	isInjection(): BBoolean {
		let visited = Set();
		this.domain().getSet().forEach(element => {
			let range = <immutable.Set<T>> this.map.get(element);
			range.forEach(rangeElement => {
				if(visited.contains(rangeElement)) {
					return new BBoolean(false);
				}
				visited = visited.union(Set([rangeElement]));
			});
		});
		return new BBoolean(true);
	}

	isBijection(range: BSet<T>): BBoolean {
		return this.isSurjection(range).and(this.isInjection());
	}

	isBijectionInteger(): BBoolean {
		return new BBoolean(false);
	}

	isBijectionNatural(): BBoolean {
		return new BBoolean(false);
	}

	isBijectionNatural1(): BBoolean {
		return new BBoolean(false);
	}

	isBijectionString(): BBoolean {
		return new BBoolean(false);
	}

	isBijectionStruct(): BBoolean {
		return new BBoolean(false);
	}

	
	toString(): string {
		let size: number = this.size();
		let i: number = 0;

		let sb: string = "";
		sb = sb + "{";
		for(let domainElement of this.map.keys()) {
			let range = <immutable.Set<T>> this.map.get(domainElement)
			range.forEach(rangeElement => {
				sb += "(";
				sb += domainElement.toString();
				sb += " |-> ";
				sb += rangeElement.toString();
				sb += ")";
				if (i+1 < size) {
					sb += ", ";
				}
				i++;
			});
		}
		sb += "}";
		return sb.toString();
	}

	hashCode(): number {
		return this.map.hashCode()
	}
}