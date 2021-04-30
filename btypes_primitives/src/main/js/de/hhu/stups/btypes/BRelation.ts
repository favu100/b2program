import {BTuple} from "./BTuple";
import {BSet} from "./BSet";
import {BInteger} from "./BInteger";
import { BBoolean } from "./BBoolean";
import {BString} from "./BString";
import {BStruct} from "./BStruct";

const {Map} = require('immutable')
const {Set} = require('immutable')

export class BRelation<S,T> {

	map;

	constructor(...args: any[]) {
		if (args.length === 0) {
			this.map = new Map()
		} else if (args.length == 1 && args[0] instanceof Map) {
			this.map = args[0]
		} else {
			this.map = new Map()
			for (let e of args) {
				let key = e.projection1()
				let value = e.projection2()
				let set = this.map.get(key)
				if (set == null) {
					set = new Set()
				}
				set = set.add(value)
				this.map = this.map.set(key, set)
			}
		}
	}

	static fromSet<S,T>(set: BSet<BTuple<S, T>> ): BRelation<S,T> {
		let resultMap = new Map();
		set.getSet().forEach(e => {
			let key: S = e.projection1();
			let value: T = e.projection2();
			let range: Set<T> = resultMap.get(key);
			if(range == null) {
				range = Set(value);
				resultMap = resultMap.set(key, range);
			} else {
				range = range.add(value);
				resultMap = resultMap.set(key, range);
			}
		});
		return new BRelation<S,T>(resultMap);
	}

	equals(o): boolean {
		if (this === o)
			return true;
		if (o == null || o !instanceof BRelation)
			return false;

		return this.map === o.map;
	}

	intersect(relation: BRelation<S, T>): BRelation<S,T>  {
		let otherMap: Map<S, Set<T>> = relation.map;
		let otherDomain = otherMap.keys();
		let thisDomain = new Set(this.map.keys());
		let intersectionDomain: Set<S> = Set.intersect(thisDomain, otherDomain);
		let differenceDomain  = thisDomain.subtract(otherDomain);
		let resultMap: Map<S, Set<T>> = this.map;

		intersectionDomain.forEach(domainElement => {
			let thisRangeSet: Set<T> = this.map.get(domainElement);
			let otherRangeSet: Set<T> = otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, Set.intersect(thisRangeSet, otherRangeSet));
		});

		differenceDomain.forEach(domainElement => {
			resultMap = resultMap.set(domainElement, new Set());
		});

		return new BRelation<S,T>(resultMap);
	}

	difference(relation: BRelation<S, T>): BRelation<S, T> {
		let otherMap: Map<S, Set<T>> = relation.map;
		let otherDomain = otherMap.keys();
		let thisDomain = new Set(this.map.keys());
		let differenceDomain = thisDomain.subtract(otherDomain);
		let restDomain = thisDomain.subtract(differenceDomain);

		let resultMap: Map<S, Set<T>> = this.map;
		differenceDomain.forEach(domainElement => {
			let thisRangeSet = this.map.get(domainElement);
			let otherRangeSet = otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, thisRangeSet.subtract(otherRangeSet));
		});

		restDomain.forEach(domainElement => {
			resultMap = resultMap.set(domainElement, new Set());
		});
		return new BRelation<S,T>(resultMap);
	}

	union(relation: BRelation<S, T>): BRelation<S, T> {
		let otherMap = relation.map;
		let otherDomain = new Set(otherMap.keys());

		let resultMap = this.map;
        for (let domainElement of otherDomain) {
			let thisRangeSet = this.map.get(domainElement);
			let otherRangeSet = otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, Set.union(thisRangeSet, otherRangeSet));
		}
		return new BRelation<S,T>(resultMap);
	}

	size(): number {
		let size: number = 0;
		let thisDomain = new Set(this.map.keys());

		for(let domainElement of thisDomain) {
			let thisRangeSet = this.map.get(domainElement);
			size += thisRangeSet.size;
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

		let domain = this.map.keys();

		if(prj1 !in domain) {
			return new BBoolean(false);
		}

		let range = this.map.get(prj1);

		return new BBoolean(prj2 in range);
	}

	notElementOf(object: BTuple<S,T> ): BBoolean {
		let prj1: S = object.projection1();
		let prj2: T = object.projection2();

		let domain = this.map.keys();

		if(prj1 !in domain) {
			return new BBoolean(true);
		}

		let range = this.map.get(prj1);

		return new BBoolean(prj2 !in range);
	}

	relationImage(domain: BSet<S> ): BSet<T> {
		let resultSet = new Set;
		domain.getSet().forEach(domainElement => {
			let thisRangeSet = this.map.get(domainElement);
			if(thisRangeSet != null) {
				resultSet = resultSet.union(thisRangeSet);
			}
		});
		return new BSet<T>(resultSet);
	}


	functionCall(arg: S): T {
		let range = this.map.get(arg);
		if(range == null) {
			throw new Error("Argument is not in the domain of this relation");
		}
		range.forEach(element => {
			return element;
		});
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
			let currentSet: BRelation<S,T> = queue.pop();

			for(let domainElement of thisDomain) {
				let range = thisMap.get(domainElement);
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
		let thisMap: Map<S, Set<T>> = this.map;
		let set = Set(this.map.keys());
		let resultSet = set;
		for(let domainElement of set) {
			let range = this.map.get(domainElement)
			if(range.size === 0) {
				resultSet = resultSet.subtract(new Set(domainElement));
			}
		}
		return new BSet<S>(resultSet);
	}

	range(): BSet<T> {
		let set = Set.union(this.map.values());
		return new BSet<T>(set);
	}

	inverse(): BRelation<T,S> {
		let thisMap: Map<S, Set<T>> = this.map;
		let keys = new Set(thisMap.keys());

		let resultMap = new Set();
		for(let domainElement of keys) {
			let range = this.map.get(domainElement)
			range.forEach(rangeElement => {
				let currentRange = resultMap.get(rangeElement);
				if(currentRange == null) {
					currentRange = new Set();
				}
				currentRange = currentRange.union(new Set(domainElement));
				resultMap = resultMap.set(rangeElement, currentRange);
			});
		}
		return new BRelation<T, S>(resultMap);
	}

	domainRestriction(arg: BSet<S>): BRelation<S,T> {
		let set = new Set(this.map.keys());
		let otherSet = arg.getSet();
		let resultSet = set.subtract(otherSet);
		let resultMap = this.map;
		for(let obj of resultSet) {
			resultMap = resultMap.delete(obj);
		}
		return new BRelation<S,T>(resultMap);
	}
	
	domainSubstraction(arg: BSet<S>): BRelation<S,T> {
		let set = this.map.keys();
		let otherSet = arg.getSet();
		let resultMap = this.map;
		otherSet.forEach(obj => {
			resultMap = resultMap.delete(obj);
		});
		return new BRelation<S,T>(resultMap);
	}
	
	rangeRestriction(arg: BSet<T>): BRelation<S,T> {
		let otherSet: Set<T> = arg.getSet();
		let thisDomain = new Set(this.map.keys());

		let resultMap = this.map
		for(let domainElement of thisDomain) {
			let thisRangeSet = this.map.get(domainElement);
			resultMap = resultMap.set(domainElement, thisRangeSet.intersect(otherSet));
		}
		return new BRelation<S, T>(resultMap);
	}

	rangeSubstraction(arg: BSet<T>): BRelation<S, T> {
		let otherSet = arg.getSet();
		let thisDomain = new Set(this.map.keys());

		let resultMap = this.map
		for(let domainElement of thisDomain) {
			let thisRangeSet = this.map.get(domainElement);
			resultMap = resultMap.set(domainElement, thisRangeSet.subtract(otherSet));
		}
		return new BRelation<S, T>(resultMap);
	}
	
	override(arg: BRelation<S,T>): BRelation<S,T> {
		let otherMap = arg.map;

		let otherDomain = new Set(otherMap.keys());

		let resultMap = this.map;
		for(let domainElement of otherDomain) {
			let range = otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, range);
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
		let resultMap: Map<S, Set<T>> = new Map()
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let rangeElement: T = this.functionCall(<S><unknown>size.minus(i).succ());
			resultMap = resultMap.set(<S><unknown>i, new Set(rangeElement));
		}
		return new BRelation<S, T>(resultMap);
	}

	front(): BRelation<S,T> {
		return this.domainSubstraction(new BSet(this.card()));
	}
	
	tail(): BRelation<S,T> {
		let size: BInteger = this.card()
		let resultMap: Map<S, Set<T>> = new Map()
		for(let i: BInteger = new BInteger(2); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let rangeElement: T = this.functionCall(<S><unknown>i);
			resultMap = resultMap.set(<S><unknown>i.pred(),new Set(rangeElement));
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
			resultMap = resultMap.set(<S><unknown>i, new Set());
		}
		return new BRelation<S, T>(resultMap);
	}
	
	drop(n: BInteger): BRelation<S,T> {
		let size: BInteger = this.card();
		let thisMap: Map<S, Set<T>> = this.map;
		let resultMap: Map<S, Set<T>> = new Map();
		for(let i: BInteger = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let currentSet = thisMap.get(<S><unknown>i);
			resultMap = resultMap.set(<S><unknown>i.minus(n), currentSet);
		}
		return new BRelation<S, T>(resultMap);
	}
	
	concat(arg: BRelation<S,T>): BRelation<S,T> {
		let resultMap = this.map
		let otherMap = arg.map;
		let size: BInteger = this.card();
		for(let i: BInteger = new BInteger(1); i.lessEqual(arg.card()).booleanValue(); i = i.succ()) {
			resultMap = resultMap.set(<S><unknown>size.plus(i), otherMap.get(<S><unknown>i));
		}
		return new BRelation<S, T>(resultMap);
	}
	
	conc<R,A>(): BRelation<R,A> {
		let result: BRelation<R,A> = new BRelation<R,A>();
		let size: BInteger = this.card();
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			result = result.concat(<BRelation<R, A>><unknown>this.functionCall(<S><unknown>i));
		}
		return result;
	}
	
	append(arg: T): BRelation<S,T> {
		let resultMap = this.map
		resultMap = resultMap.set(<S><unknown>this.card().succ(), new Set(arg));
		return new BRelation<S, T>(resultMap);
	}
	
	prepend(arg: T): BRelation<S,T> {
		let resultMap: Map<S, Set<T>> = new Map()
		let thisMap: Map<S, Set<T>> = this.map;
		let size: BInteger = this.card()
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			resultMap = resultMap.set(<S><unknown>i.succ(), thisMap.get(<S><unknown>i));
		}
		resultMap = resultMap.set(<S><unknown>new BInteger(1), new Set(arg));
		return new BRelation<S, T>(resultMap);
	}

	directProduct<R>(arg: BRelation<S,R>): BRelation<S,BTuple<T,R>> {
		let thisMap: Map<S, Set<T>> = this.map;
		let thisDomain = new Set(thisMap.keys());
		let otherMap = arg.map;

		let resultMap: Map<S, Set<T>> = new Map()
		for(let domainElement of thisDomain) {
			let thisRange = this.map.get(domainElement)
			let otherRange = otherMap.get(domainElement);
			if(otherRange == null) {
				continue;
			}
			let resultRange = new Set();
			thisRange.forEach(lhs => {
				otherRange.forEach(rhs => {
					resultRange = Set.union(resultRange, new Set(new BTuple<T,R>(lhs, rhs)));
				});
			});
			resultMap = resultMap.set(domainElement, resultRange);
		}
		return new BRelation<S, BTuple<T, R>>(resultMap);
	}
	
	parallelProduct<R,A>(arg: BRelation<R,A>): BRelation<BTuple<S,R>,BTuple<T,A>> {
		let thisMap: Map<S, Set<T>> = this.map;
		let thisDomain = new Set(thisMap.keys());

		let otherMap = arg.map;
		let otherDomain = new Set(otherMap.keys());

		let resultMap: Map<S, Set<T>> = new Map()

		for(let domainElementThis of thisDomain) {
			for(let domainElementOther of otherDomain) {
				let thisRange = thisMap.get(domainElementThis);
				let otherRange = otherMap.get(domainElementOther);

				let resultRange = new Set();
				thisRange.forEach(lhs => {
					otherRange.forEach(rhs => {
						resultRange = resultRange.union(new Set(new BTuple<T,A>(lhs, rhs)));
					});
				});
				let tuple: BTuple<S,R> = new BTuple<S,R>(domainElementThis, domainElementOther);
				resultMap = resultMap.set(<S><unknown>tuple, resultRange);
			}
		}
		return new BRelation<BTuple<S, R>, BTuple<T, A>>(resultMap);
	}

	
	composition<R>(arg: BRelation<T,R>): BRelation<S,R> {
		let thisMap: Map<S, Set<T>> = this.map;
		let otherMap = arg.map;

		let thisDomain = new Set(thisMap.keys());

		let resultMap: Map<S, Set<T>> = new Map()

		for(let domainElement of thisDomain) {
			let range = this.map.get(domainElement)

			let set = new Set();
			range.forEach(rangeElement => {
				set = set.union(otherMap.get(rangeElement));
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
		let lastResult: BRelation<S,S> = null;
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


    static projection1<S,T>(arg1: BSet<S>, arg2: BSet<T>): BRelation<BTuple<S,T>, S> {
		let argSet1 = arg1.getSet();
		let argSet2 = arg2.getSet();

		let resultMap: Map<BTuple<S, T>, Set<T>> = new Map()
		argSet1.forEach(e1 => {
			argSet2.forEach(e2 => {
				let tuple: BTuple<S,T> = new BTuple<S,T>(e1, e2);
				resultMap = resultMap.set(tuple, new Set(e1));
			});
		});
		return new BRelation<BTuple<S, T>, S>(resultMap);
	}


	static projection2<S,T>(arg1: BSet<S>, arg2: BSet<T>):  BRelation<BTuple<S,T>, T> {
		let argSet1 = arg1.getSet();
		let argSet2 = arg2.getSet();

		let resultMap: Map<BTuple<S, T>, Set<T>> = new Map()
		argSet1.forEach(e1 => {
			argSet2.forEach(e2 => {

				let tuple: BTuple<S,T> = new BTuple<S,T>(e1, e2);
				resultMap = resultMap.set(tuple, new Set(e2));
			});
		});
		return new BRelation<BTuple<S, T>, T>(resultMap);
	}

	
	fnc(): BRelation<S,BSet<T>> {
		let thisMap: Map<S, Set<T>> = this.map;
		let domain = this.domain().getSet();

		let resultMap: Map<S, Set<T>> = new Map()
		domain.forEach(domainElement => {
			let range = thisMap.get(domainElement);
			let rangeSet: BSet<T> = new BSet<T>(range);
			resultMap = resultMap.set(domainElement, new Set(rangeSet));
		});
		return new BRelation<S, BSet<T>>(resultMap);
	}

	rel<R>(): BRelation<S,R> {
		let domain: Set<S> = this.domain().getSet();

		let resultMap: Map<S, Set<T>> = new Map()
		domain.forEach(domainElement => {
			let range: BSet<R> = <BSet<R>><unknown>this.functionCall(domainElement);
			let rangeSet = range.getSet();
			resultMap = resultMap.set(domainElement, <Set<T>><unknown>rangeSet);
		});
		return new BRelation<S, R>(resultMap);
	}

    static identity<T>(arg: BSet<T>):  BRelation<T,T> {
		let resultMap: Map<T, Set<T>> = new Map()
		arg.getSet().forEach(e => {
			resultMap = resultMap.set(e, new Set(e));
		});
		return new BRelation<T, T>(resultMap);
	}


	static cartesianProduct<S,T>(arg1: BSet<S>, arg2: BSet<T>): BRelation<S,T> {
		let resultMap: Map<S, Set<T>> = new Map()
		arg1.getSet().forEach(e1 => {
			resultMap = resultMap.set(e1, arg2.getSet());
		});
		return new BRelation<S, T>(resultMap);
	}

	
	nondeterminism(): BTuple<S,T> {
		let thisMap: Map<S, Set<T>> = this.map;
		let domain = new Set(this.map.keys());

		let index: number = Math.floor(Math.random() * domain.size);
		let i: number = 0;
		let domainElement: S = null;
		for(let obj of domain) {
			if(i == index) {
				domainElement = obj;
				break;
			}
			i++;
		}

		let range = this.map.get(domainElement);
		index = Math.floor(Math.random() * range.size);
		i = 0;
		range.forEach(obj => {
			if(i == index) {
				return new BTuple<S,T>(domainElement, obj);
			}
			i++;
		});
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
			let range = this.map.get(element);
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
		let visited = new Set();
		this.domain().getSet().forEach(element => {
			let range = this.map.get(element);
			range.forEach(rangeElement => {
				if(visited.contains(rangeElement)) {
					return new BBoolean(false);
				}
				visited = visited.union(new Set(rangeElement));
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

		let thisMap: Map<S, Set<T>> = this.map;
		let domain = new Set(this.map.keys());

		let size: number = this.size();
		let i: number = 0;

		let sb: string = "";
		sb = sb + "{";
		for(let domainElement of domain) {
			let range = this.map.get(domainElement)
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
}
