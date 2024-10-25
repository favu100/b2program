import {BTuple} from "./BTuple.js";
import {BSet} from "./BSet.js";
import {BInteger} from "./BInteger.js";
import {BBoolean} from "./BBoolean.js";
import {BString} from "./BString.js";
import {BStruct} from "./BStruct.js";
import {BObject} from "./BObject.js";

import * as immutable from "../immutable/dist/immutable.es.js";

export class BRelation<S extends BObject,T extends BObject> implements BObject, Iterable<BTuple<S,T>> {

	map: immutable.Map<S, immutable.Set<T>>;

	constructor(...args: any[]) {
		if (args.length === 0) {
			this.map = immutable.Map()
		} else if (args.length == 1 && args[0] instanceof immutable.Map) {
			this.map = args[0] as immutable.Map<S, immutable.Set<T>>
		} else {
			this.map = immutable.Map()
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
		let resultMap = immutable.Map();
		set.getSet().forEach((e: BTuple<S, T>) => {
			let key: S = e.projection1();
			let value: T = e.projection2();
			let range: any = resultMap.get(key);
			if(range == null) {
				range = immutable.Set([value]);
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
		let otherDomain = immutable.Set(otherMap.keys());
		let thisDomain = immutable.Set(this.map.keys());
		let intersectionDomain = thisDomain.intersect(otherDomain);
		let differenceDomain  = thisDomain.subtract(otherDomain);
		let resultMap: immutable.Map<S, immutable.Set<T>> = this.map;

		intersectionDomain.forEach((domainElement: S) => {
			let thisRangeSet: immutable.Set<T> = <immutable.Set<T>> this.map.get(domainElement);
			let otherRangeSet = <immutable.Set<T>> otherMap.get(domainElement);
			let newRangeSet = <immutable.Set<T>> thisRangeSet.intersect(otherRangeSet);
			if(newRangeSet.size === 0) {
			    resultMap = resultMap.delete(domainElement);
			} else {
			    resultMap = resultMap.set(domainElement, newRangeSet);
			}
		});

		differenceDomain.forEach((domainElement: S) => {
			resultMap = resultMap.delete(domainElement);
		});

		return new BRelation<S,T>(resultMap);
	}

	difference(relation: BRelation<S, T>): BRelation<S, T> {
		let otherMap: immutable.Map<S, immutable.Set<T>> = relation.map;
		let otherDomain = immutable.Set(otherMap.keys());
		let thisDomain = immutable.Set(this.map.keys());
		let intersectionDomain = thisDomain.intersect(otherDomain);

		let resultMap: immutable.Map<S, immutable.Set<T>> = this.map;
		for(let domainElement of intersectionDomain) {
			let thisRangeSet = <immutable.Set<T>> this.map.get(domainElement);
			let otherRangeSet = <immutable.Set<T>> otherMap.get(domainElement);
            if(otherRangeSet == null) {
                continue;
            }
			let newRangeSet = <immutable.Set<T>> thisRangeSet.subtract(otherRangeSet);
            if(newRangeSet.size === 0) {
                resultMap = resultMap.delete(domainElement);
            } else {
                resultMap = resultMap.set(domainElement, newRangeSet);
            }
		}
		return new BRelation<S,T>(resultMap);
	}

	union(relation: BRelation<S, T>): BRelation<S, T> {
		let otherMap = relation.map;
		let otherDomain = immutable.Set(otherMap.keys());

		let resultMap = this.map;
        for (let domainElement of otherDomain) {
			let thisRangeSet = this.map.get(domainElement);
			let otherRangeSet = <immutable.Set<T>> otherMap.get(domainElement);
			resultMap = resultMap.set(domainElement, thisRangeSet == null? otherRangeSet:otherRangeSet == null? otherRangeSet: thisRangeSet.union(otherRangeSet));
		}
		return new BRelation<S,T>(resultMap);
	}

	size(): number {
		let size: number = 0;
		let thisDomain = immutable.Set(this.map.keys());

		for(let domainElement of thisDomain) {
			let thisRangeSet = this.map.get(domainElement);
			if(thisRangeSet == null) {
				continue;
			}
			size += thisRangeSet.size;
		}
		return size;
	}

	_size(): BInteger {
	    return new BInteger(this.size());
	}

	card(): BInteger {
		return new BInteger(this.size());
	}

	equal(other: any): BBoolean {
	    return this.subset(other).and(other.subset(this));
	}

	unequal(other: any): BBoolean {
		return this.equal(other).not();
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
		let resultSet = immutable.Set();
		for (let domainElement of domain){
            let thisRangeSet: immutable.Set<T> = <immutable.Set<T>> this.map.get(domainElement);
            if(thisRangeSet != null) {
                resultSet = BSet.immutableSetUnion(resultSet, thisRangeSet);
            }
		}
		return new BSet<T>(resultSet);
	}


	functionCall(arg: S): T {
		let range = this.map.get(arg);

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
		let thisDomain = immutable.Set(thisMap.keys());


		let result: BSet<BRelation<S,T>> = new BSet<BRelation<S,T>>();
		let start: BRelation<S,T> = new BRelation();
		let queue = [];
		queue.push(start);
		result = result.union(new BSet<BRelation<S,T>>(start));
		while(queue.length !== 0) {
			let currentSet: BRelation<S,T> = <BRelation<S, T>>queue.pop();

			for(let domainElement of thisDomain) {
				let range = <immutable.Set<T>> thisMap.get(domainElement);
				range.forEach((rangeElement: T) => {
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
		let resultSet = immutable.Set(this.map.keys());
		for(let domainElement of this.map.keys()) {
			let range = <immutable.Set<T>> this.map.get(domainElement)
			if(range == null || range.size === 0) {
				resultSet = resultSet.remove(domainElement);
			}
		}
		return new BSet<S>(resultSet);
	}

    domainForRelations<R extends BObject,A extends BObject>(): BRelation<R,A> {
		let result = new BRelation<R,A>();
		for(let elem of this.domain()) {
			result = result.union(new BRelation<R,A>(elem));
		}
		return result;
	}

	isInDomain(arg: S): BBoolean {
	    let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
	    let image = thisMap.get(arg);
	    if(image == null || image.size === 0) {
	        return new BBoolean(false);
	    }
	    return new BBoolean(true);
	}

    isNotInDomain(arg: S): BBoolean {
        return this.isInDomain(arg).not();
    }

	range(): BSet<T> {
		let set = immutable.Set.union(this.map.values());
		return new BSet<T>(set);
	}

    rangeForRelations<R extends BObject,A extends BObject>(): BRelation<R,A> {
		let result = new BRelation<R,A>();
		for(let elem of this.range()) {
			result = result.union(new BRelation<R,A>(elem));
		}
		return result;
	}

    isInRange(element: T): BBoolean {
        for(let domainElement of this.map.keys()) {
            let range = <immutable.Set<T>> this.map.get(domainElement)
            if(range != null && range.has(element)) {
                return new BBoolean(true);
            }
        }
        return new BBoolean(false);
    }

    isNotInRange(element: T): BBoolean {
        return this.isInRange(element).not();
    }

    isInRelationalImage(element: T, set: BSet<S>): BBoolean {
        for (let key of set) {
            let image = <immutable.Set<T>> this.map.get(key)
            if(image != null && image.has(element)) {
                return new BBoolean(true);
            }
        }
        return new BBoolean(false);
    }

    isNotInRelationalImage(element: T, set: BSet<S>): BBoolean {
        return this.isInRelationalImage(element, set).not();
    }

	inverse(): BRelation<T,S> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let keys = immutable.Set(thisMap.keys());

		let resultMap: immutable.Map<T, immutable.Set<S>> = immutable.Map<T, immutable.Set<S>>();
		for(let domainElement of keys) {
			let range: immutable.Set<T> = <immutable.Set<T>> thisMap.get(domainElement)
			if(range == null) {
			    break;
			}
			for(let rangeElement of range) {
                let currentRange = resultMap.get(rangeElement);
                if(currentRange == null) {
                    currentRange = immutable.Set();
                }
                currentRange = currentRange.union(immutable.Set([domainElement]));
                resultMap = resultMap.set(rangeElement, currentRange);
			}
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
		let thisDomain = immutable.Set(this.map.keys());

		let resultMap = this.map
		for(let domainElement of thisDomain) {
			let thisRangeSet = <immutable.Set<T>> this.map.get(domainElement);
            let newRangeSet = <immutable.Set<T>> BSet.immutableSetIntersection(thisRangeSet, otherSet);
            if(newRangeSet.size === 0) {
                resultMap = resultMap.delete(domainElement);
            } else {
                resultMap = resultMap.set(domainElement, newRangeSet);
            }
		}
		return new BRelation<S, T>(resultMap);
	}

	rangeSubstraction(arg: BSet<T>): BRelation<S, T> {
		let otherSet = arg.getSet();
		let thisDomain = immutable.Set(this.map.keys());

		let resultMap = this.map
		for(let domainElement of thisDomain) {
			let thisRangeSet = <immutable.Set<T>> this.map.get(domainElement);
			let newRangeSet = <immutable.Set<T>> BSet.immutableSetDifference(thisRangeSet, otherSet);
            if(newRangeSet.size === 0) {
                resultMap = resultMap.delete(domainElement);
            } else {
                resultMap = resultMap.set(domainElement, newRangeSet);
            }
		}
		return new BRelation<S, T>(resultMap);
	}

    subset(arg: BRelation<S,T>): BBoolean {
        let thisDomain = immutable.Set(this.map.keys());

        for(let domainElement of thisDomain) {
            let thisRangeSet = <immutable.Set<T>> this.map.get(domainElement);
            let otherRangeSet = <immutable.Set<T>> arg.map.get(domainElement);
            if(thisRangeSet != null && !(thisRangeSet.size === 0)) {
                if(otherRangeSet == null) {
                    return new BBoolean(false);
                }
                for(let rangeElement of thisRangeSet) {
                    if(!otherRangeSet.contains(rangeElement)) {
                        return new BBoolean(false);
                    }
                }
            }
        }
        return new BBoolean(true);
    }

    notSubset(arg: BRelation<S,T>): BBoolean {
        return this.subset(arg).not();
    }

	strictSubset(other: BRelation<S,T>): BBoolean {
	    return new BBoolean(other.size() != this.size() && this.subset(other).booleanValue());
	}

	strictNotSubset(other: BRelation<S,T>): BBoolean {
	    return this.strictSubset(other).not();
	}

	override(arg: BRelation<S,T>): BRelation<S,T> {
		let otherMap = arg.map;
		let otherDomain = immutable.Set(otherMap.keys());
		let resultMap = this.map;

		for(let domainElement of otherDomain) {
		    let range: immutable.Set<T> = <immutable.Set<T>> otherMap.get(domainElement);
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
		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map()
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let rangeElement: T = this.functionCall(<S><unknown>size.minus(i).succ());
			resultMap = resultMap.set(<S><unknown>i, immutable.Set([rangeElement]));
		}
		return new BRelation<S, T>(resultMap);
	}

	front(): BRelation<S,T> {
		return this.domainSubstraction(new BSet(this.card()));
	}

	tail(): BRelation<S,T> {
		let size: BInteger = this.card()
		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map()
		for(let i: BInteger = new BInteger(2); i.lessEqual(size).booleanValue(); i = i.succ()) {
			let rangeElement: T = this.functionCall(<S><unknown>i);
			resultMap = resultMap.set(<S><unknown>i.pred(), immutable.Set([rangeElement]));
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
		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map();
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
		resultMap = resultMap.set(<S><unknown>this.card().succ(), immutable.Set([arg]));
		return new BRelation<S, T>(resultMap);
	}

	prepend(arg: T): BRelation<S,T> {
		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map()
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let size: BInteger = this.card()
		for(let i: BInteger = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
			resultMap = resultMap.set(<S><unknown>i.succ(), <immutable.Set<T>> thisMap.get(<S><unknown>i));
		}
		resultMap = resultMap.set(<S><unknown>new BInteger(1), immutable.Set([arg]));
		return new BRelation<S, T>(resultMap);
	}

	directProduct<R extends BObject>(arg: BRelation<S,R>): BRelation<S,BTuple<T,R>> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let thisDomain: immutable.Set<S> = immutable.Set(thisMap.keys());
		let otherMap: immutable.Map<S, immutable.Set<R>> = arg.map;

		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map()
		for(let domainElement of thisDomain) {
			let thisRange: immutable.Set<T> = <immutable.Set<T>> this.map.get(domainElement)
			let otherRange = otherMap.get(domainElement);
			if(otherRange == undefined) {
				continue;
			}
			let resultRange = immutable.Set();
			thisRange.forEach((lhs: T) => {
				otherRange!.forEach((rhs: R) => {
					resultRange = immutable.Set.union([resultRange, immutable.Set([new BTuple<T,R>(lhs, rhs)])]);
				});
			});
			resultMap = resultMap.set(domainElement, resultRange);
		}
		return new BRelation<S, BTuple<T, R>>(resultMap);
	}

	parallelProduct<R extends BObject,A extends BObject>(arg: BRelation<R,A>): BRelation<BTuple<S,R>,BTuple<T,A>> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let thisDomain = immutable.Set(thisMap.keys());

		let otherMap: immutable.Map<R, immutable.Set<A>> = arg.map;
		let otherDomain = immutable.Set(otherMap.keys());

		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map()

		for(let domainElementThis of thisDomain) {
			for(let domainElementOther of otherDomain) {
				let thisRange: immutable.Set<T> = <immutable.Set<T>> thisMap.get(domainElementThis);
				let otherRange: immutable.Set<A> = <immutable.Set<A>> otherMap.get(domainElementOther);

				let resultRange = immutable.Set();
				thisRange.forEach((lhs: T) => {
					otherRange.forEach((rhs: A) => {
						resultRange = resultRange.union(immutable.Set([new BTuple<T, A>(lhs, rhs)]));
					});
				});
				let tuple: BTuple<S,R> = new BTuple<S,R>(domainElementThis, domainElementOther);
				resultMap = resultMap.set(<S><unknown>tuple, resultRange);
			}
		}
		return new BRelation<BTuple<S, R>, BTuple<T, A>>(resultMap);
	}


	composition<R extends BObject>(arg: BRelation<T,R>): BRelation<S,R> {
		let otherMap: immutable.Map<T, immutable.Set<R>> = arg.map;
		let resultMap: immutable.Map<S, immutable.Set<R>> = immutable.Map()

		for(let domainElement of this.map.keys()) {
			let range: immutable.Set<T> = this.map.get(domainElement)
			let set: immutable.Set<R> = immutable.Set<R>();

			if(range == null) {
			    break;
			}

			for(let rangeElement of range) {
                let union_element = otherMap.get(rangeElement)
                if (union_element == null) {
                    continue;
                }
                set = set.union(<immutable.Set<R>> otherMap.get(rangeElement));
			}
            if(set.size === 0) {
                continue;
            }
			resultMap = resultMap.set(domainElement, set);
		}
		return new BRelation<S, R>(resultMap);
	}

	isInComposition<R extends BObject>(tuple: BTuple<S,R>, arg: BRelation<T,R>): BBoolean {
		let projection1 = tuple.projection1();
		let projection2 = tuple.projection2();

		let range: immutable.Set<T> = this.map.get(projection1)

		if(range != null) {
			for (let value of range) {
			    let range2: immutable.Set<T> = arg.map.get(value)
				if (range2 != null && range2.has(projection2)) {
					return new BBoolean(true);
				}
			}
		}
		return new BBoolean(false);
	}

	isNotInComposition<R extends BObject>(tuple: BTuple<S,R>, arg: BRelation<T,R>): BBoolean {
	    return this.isInComposition(tuple, arg).not();
	}

	iterate(n: BInteger): BRelation<S,S> {
		let thisRelation: BRelation<S,S> = <BRelation<S,S>><unknown>this;
		let result: BRelation<S,S> = BRelation.identity(this.domain().union(<immutable.Set<S>> this.range()));
		for(let i: BInteger = new BInteger(1); i.lessEqual(n).booleanValue(); i = i.succ()) {
			result = result.composition(thisRelation);
		}
		return result;
	}


	closure(): BRelation<S,S> {
		let thisRelation: BRelation<S,S> = <BRelation<S, S>><unknown>this;
		let result: BRelation<S,S> = BRelation.identity(this.domain().union(<immutable.Set<S>> this.range()));
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

		let resultMap: immutable.Map<BTuple<BObject, BObject>, immutable.Set<BObject>> = immutable.Map()
		argSet1.forEach((e1: S) => {
			argSet2.forEach((e2: T) => {
				let tuple: BTuple<S,T> = new BTuple<S,T>(e1, e2);
				resultMap = resultMap.set(tuple, immutable.Set([e1]));
			});
		});
		return new BRelation<BTuple<S, T>, S>(resultMap);
	}


	static projection2<S extends BObject,T extends BObject>(arg1: BSet<S>, arg2: BSet<T>):  BRelation<BTuple<S,T>, T> {
		let argSet1 = arg1.getSet();
		let argSet2 = arg2.getSet();

		let resultMap: immutable.Map<BTuple<S, T>, immutable.Set<T>> = immutable.Map()
		argSet1.forEach((e1: S) => {
			argSet2.forEach((e2: T) => {

				let tuple: BTuple<S,T> = new BTuple<S,T>(e1, e2);
				resultMap = resultMap.set(tuple, immutable.Set([e2]));
			});
		});
		return new BRelation<BTuple<S, T>, T>(resultMap);
	}


	fnc(): BRelation<S,BSet<T>> {
		let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
		let domain: immutable.Set<S> = this.domain().getSet();

		let resultMap: immutable.Map<S, immutable.Set<BSet<T>>> = immutable.Map()
		domain.forEach((domainElement: S) => {
			let range = thisMap.get(domainElement);
			let rangeSet: BSet<T> = new BSet<T>(range);
			resultMap = resultMap.set(domainElement, immutable.Set([rangeSet]));
		});
		return new BRelation<S, BSet<T>>(resultMap);
	}

	rel<R extends BObject>(): BRelation<S,R> {
		let domain: immutable.Set<S> = this.domain().getSet();

		let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map()
		domain.forEach((domainElement: S) => {
			let range: BSet<R> = <BSet<R>><unknown>this.functionCall(domainElement);
			let rangeSet = range.getSet();
			resultMap = resultMap.set(domainElement, <Set<T>><unknown>rangeSet);
		});
		return new BRelation<S, R>(resultMap);
	}

    static identity<T extends BObject>(arg: BSet<T>):  BRelation<T,T> {
		let resultMap: immutable.Map<T, immutable.Set<T>> = immutable.Map()
		arg.getSet().forEach((e: T) => {
			resultMap = resultMap.set(e, immutable.Set([e]));
		});
		return new BRelation<T, T>(resultMap);
	}


	static cartesianProduct<S extends BObject, T extends BObject>(arg1: BSet<S>, arg2: BSet<T>): BRelation<S, T>;
	static cartesianProduct<S extends BObject, T extends BObject, R extends BObject>(arg1: BRelation<S, T>, arg2: BSet<R>): BRelation<BTuple<S, T>, R>;
	static cartesianProduct<S extends BObject, T extends BObject, R extends BObject>(arg1: BSet<S>, arg2: BRelation<T, R>): BRelation<S, BTuple<T, R>>;
	static cartesianProduct<S extends BObject, T extends BObject, R extends BObject, A extends BObject>(arg1: BRelation<S, T>, arg2: BRelation<R, A>): BRelation<BTuple<S, T>, BTuple<R, A>>;
	static cartesianProduct<S extends BObject, T extends BObject, R extends BObject, A extends BObject>(arg1: BSet<S> | BRelation<S, T>, arg2: BSet<T> | BSet<R> | BRelation<T, R> | BRelation<R, A>): any {
		if (arg1 instanceof BSet && arg2 instanceof BSet) {
			let resultMap: immutable.Map<S, immutable.Set<T>> = immutable.Map();
			for(let e1 of arg1) {
				if (arg2.size().intValue() > 0) {
					resultMap = resultMap.set(e1, arg2.getSet());
				}
			}
			return new BRelation<S, T>(resultMap);
		} else if (arg1 instanceof BRelation && arg2 instanceof BSet) {
			let resultMap: immutable.Map<BTuple<S, T>, immutable.Set<R>> = immutable.Map();
			for (let e1 of arg1) {
				if (arg2.size().intValue() > 0) {
					resultMap = resultMap.set(e1, arg2.getSet());
				}
			}
			return new BRelation<BTuple<S, T>, R>(resultMap);
		} else if (arg1 instanceof BSet && arg2 instanceof BRelation) {
			let resultMap: immutable.Map<S, immutable.Set<BTuple<T, R>>> = immutable.Map();
			for(let e1 of arg1) {
				let rangeSet: immutable.Set<BTuple<T, R>> = immutable.Set();
				for (let e2 of arg2) {
					rangeSet = rangeSet.add(e2);
				}
				if (!rangeSet.isEmpty()) {
					resultMap = resultMap.set(e1, rangeSet);
				}
			}
			return new BRelation<S, BTuple<T, R>>(resultMap);
		} else if (arg1 instanceof BRelation && arg2 instanceof BRelation) {
			let resultMap: immutable.Map<BTuple<S, T>, immutable.Set<BTuple<R, A>>> = immutable.Map();
			for (let e1 of arg1) {
				let rangeSet: immutable.Set<BTuple<R, A>> = immutable.Set();
				for (let e2 of arg2) {
					rangeSet = rangeSet.add(e2);
				}
				if (!rangeSet.isEmpty()) {
					resultMap = resultMap.set(e1, rangeSet);
				}
			}
			return new BRelation<BTuple<S, T>, BTuple<R, A>>(resultMap);
		}
	}

	nondeterminism(): BTuple<S,T> | null {
		let domain = immutable.Set(this.map.keys());
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
			for (let obj of range) {
				if (i == index) {
					return new BTuple<S, T>(<S>domainElement, obj);
				}
				i++;
			}
		}
		return null;
	}

    isTotal(domain: BSet<S>): BBoolean;
    isTotal<R1 extends BObject, R2 extends BObject>(domain: BRelation<R1, R2>): BBoolean;

    isTotal<R1 extends BObject, R2 extends BObject>(domain: BRelation<R1, R2> | BSet<S>): BBoolean {
        if(domain instanceof BSet<S>) {
            return new BBoolean(this.domain().equal(domain));
        } else {
            let domainAsSet: BSet<BTuple<R1, R2>> = new BSet<BTuple<R1, R2>>();
            for(let tuple of domain) {
                domainAsSet = domainAsSet.union(new BSet<BTuple<R1, R2>>(tuple));
            }
            return this.domain().equal(<BSet<S>><unknown> domainAsSet);
        }
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

    isPartial(domain: BSet<S>): BBoolean;
    isPartial <A1 extends BObject, A2 extends BObject>(domain: BRelation<A1, A2>): BBoolean;

    isPartial <A1 extends BObject, A2 extends BObject>(domain: BSet<S> | BRelation<A1, A2>): BBoolean {
        if(domain instanceof BSet) {
            return this.domain().subset(domain);
        } else {
            for(let element of this.domain()) {
                let elementAsTuple: BTuple<A1, A2> = <BTuple<A1, A2>> element;
                let range = <immutable.Set<T>> domain.map.get(elementAsTuple.projection1());
                if(range == null) {
                    return new BBoolean(false);
                }
                if(!range.contains(elementAsTuple.projection2())) {
                    return new BBoolean(false);
                }
            }
            return new BBoolean(true);
        }
    }

    isPartialInteger(): BBoolean {
        for(let e of this.domain().getSet()) {
            if(e instanceof BInteger) {
                return new BBoolean(true);
            } else {
                return new BBoolean(false);
            }
        }
        return new BBoolean(true);
    }

    isPartialNatural(): BBoolean {
        for(let e of this.domain().getSet()) {
            if(e instanceof BInteger && !(<BInteger>e).isNatural().booleanValue()) {
                return new BBoolean(false);
            }
        }
        return new BBoolean(true);
    }

    isPartialNatural1(): BBoolean {
        for(let e of this.domain().getSet()) {
            if(e instanceof BInteger && !(<BInteger>e).isNatural1().booleanValue()) {
                return new BBoolean(false);
            }
        }
        return new BBoolean(true);
    }

    isPartialString(): BBoolean {
        for(let e of this.domain().getSet()) {
            if(e instanceof BString && !(<BString>e).isString().booleanValue()) {
                return new BBoolean(false);
            }
        }
        return new BBoolean(true);
    }

    isPartialStruct(): BBoolean {
        for(let e of this.domain().getSet()) {
            if(e instanceof BStruct && !(<BStruct>e).isRecord().booleanValue()) {
                return new BBoolean(false);
            }
        }
        return new BBoolean(true);
    }

    checkDomain(domain: BSet<S>): BBoolean;
    checkDomain <A1 extends BObject, A2 extends BObject>(domain: BRelation<A1, A2>): BBoolean;

    checkDomain <A1 extends BObject, A2 extends BObject>(domain: BSet<S> | BRelation<A1, A2>): BBoolean {
        if(domain instanceof BSet) {
            return this.domain().subset(domain);
        } else {
            for(let element of this.domain()) {
                let elementAsTuple: BTuple<A1, A2> = <BTuple<A1, A2>><unknown> element;
                let range = <immutable.Set<T>> domain.map.get(elementAsTuple.projection1());
                if(range == null) {
                    return new BBoolean(false);
                }
                if(!range.contains(elementAsTuple.projection2())) {
                    return new BBoolean(false);
                }
            }
            return new BBoolean(true);
        }
    }

	checkDomainInteger(): BBoolean {
	    for(let e of this.domain().getSet()) {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

	checkDomainNatural(): BBoolean {
	    for(let e of this.domain().getSet()) {
			if(e instanceof BInteger && !(<BInteger>e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

	checkDomainNatural1(): BBoolean {
	    for(let e of this.domain().getSet()) {
            if(e instanceof BInteger && !(<BInteger>e).isNatural1().booleanValue()) {
                return new BBoolean(false);
            }
	    }
		return new BBoolean(true);
	}

	checkDomainString(): BBoolean {
	    for(let e of this.domain().getSet()) {
			if(e instanceof BString && !(<BString>e).isString().booleanValue()) {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

	checkDomainStruct(): BBoolean {
	    for(let e of this.domain().getSet()) {
			if(e instanceof BStruct && !(<BStruct>e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

    checkRange(range: BSet<T>): BBoolean;
    checkRange <A1 extends BObject, A2 extends BObject>(range: BRelation<A1, A2>): BBoolean;

    checkRange <A1 extends BObject, A2 extends BObject>(range: BSet<T> | BRelation<A1, A2>): BBoolean {
        if(range instanceof BSet) {
            return this.range().subset(range);
        } else {
            for(let element of this.range()) {
                let elementAsTuple: BTuple<A1, A2> = <BTuple<A1, A2>><unknown> element;
                let rangeRange = <immutable.Set<T>> range.map.get(elementAsTuple.projection1());
                if(rangeRange == null) {
                    return new BBoolean(false);
                }
                if(!rangeRange.contains(elementAsTuple.projection2())) {
                    return new BBoolean(false);
                }
            }
            return new BBoolean(true);
        }
    }

	checkRangeInteger(): BBoolean {
	    for(let e of this.range().getSet()) {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

    checkRangeBoolean(): BBoolean {
        for(let e of this.range().getSet()) {
            if(e instanceof BBoolean) {
                return new BBoolean(true);
            } else {
                return new BBoolean(false);
            }
        }
        return new BBoolean(true);
    }

	checkRangeNatural(): BBoolean {
	    for(let e of this.range().getSet()) {
			if(e instanceof BInteger && !(<BInteger> e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

	checkRangeNatural1(): BBoolean {
	    for(let e of this.range().getSet()) {
			if(e instanceof BInteger && !(<BInteger> e).isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

	checkRangeString(): BBoolean {
	    for(let e of this.range().getSet()) {
			if(e instanceof BString && !(<BString> e).isString().booleanValue()) {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

	checkRangeStruct(): BBoolean {
	    for(let e of this.range().getSet()) {
			if(e instanceof BStruct && !(<BStruct> e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
	    }
		return new BBoolean(true);
	}

	isRelation(): BBoolean {
		return new BBoolean(true);
	}

	isFunction(): BBoolean {
	    for(let element of this.domain().getSet()) {
            let range = <immutable.Set<T>> this.map.get(element);
            if(range.size > 1) {
                return new BBoolean(false);
            }
	    }
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
		let visited = immutable.Set();
		for(let element of this.domain().getSet()) {
			let range = <immutable.Set<T>> this.map.get(element);
			for(let rangeElement of range) {
				if(visited.contains(rangeElement)) {
					return new BBoolean(false);
				}
				visited = visited.union(immutable.Set([rangeElement]));
			}
		}
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
			range.forEach((rangeElement: T) => {
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

    [Symbol.iterator]() {
        let thisMap: immutable.Map<S, immutable.Set<T>> = this.map;
        let keyIterator: Iterator<S> = thisMap.keys();
        let currentLhs: S = keyIterator.next().value;
        let valueIterator: Iterator<T> = currentLhs == null ? null : (<immutable.Set<T>> thisMap.get(currentLhs)).values();

        return {
            next: function() {
                // If there is no next key, then we have already iterated through the relation
                if(currentLhs == null) {
                    return {
                        done: true,
                        value: null
                    }
                }

                let nextValueIterator = valueIterator.next();

                if(valueIterator == null || nextValueIterator.value == null) {
                    currentLhs = keyIterator.next().value;
                    valueIterator = currentLhs == null ? null : (<immutable.Set<T>> thisMap.get(currentLhs)).values();
                    if(currentLhs == null) {
                        return {
                            done: true,
                            value: null
                        }
                    }

                    return {
                        done: false,
                        value: new BTuple<S,T>(currentLhs, valueIterator.next().value)
                    }
                } else {
                    return {
                        done: false,
                        value: new BTuple<S,T>(currentLhs, nextValueIterator.value)
                    }
                }


            }.bind(this)
        }
    }
}