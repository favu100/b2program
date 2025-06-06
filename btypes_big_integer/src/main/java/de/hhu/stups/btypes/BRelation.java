package de.hhu.stups.btypes;

import clojure.java.api.Clojure;
import clojure.lang.PersistentHashSet;
import clojure.lang.PersistentHashMap;
import clojure.lang.RT;
import clojure.lang.Var;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Objects;

/**
 * Created by fabian on 15.01.19.
 */
public class BRelation<S,T> implements BObject, Iterable<BTuple<S,T>> {

	protected static final Var ASSOC;

	protected static final Var DISSOC;

	protected static final Var GET;

	protected static final Var SET;

	protected static final Var SEQ;

	protected static final Var LIST;

	protected static final Var KEYS;

	protected static final Var VALS;

	protected static final Var CONTAINS;

	protected static final Var REDUCE;

	protected static final Var INTERSECTION;

	protected static final Var UNION;

	protected static final Var DIFFERENCE;

	static {
		RT.var("clojure.core", "require").invoke(Clojure.read("clojure.set"));
		ASSOC = RT.var("clojure.core", "assoc");
		DISSOC = RT.var("clojure.core", "dissoc");
		GET = RT.var("clojure.core", "get");
		SET = RT.var("clojure.core", "set");
		SEQ = RT.var("clojure.core", "seq");
		LIST = RT.var("clojure.core", "list");
		KEYS = RT.var("clojure.core", "keys");
		VALS = RT.var("clojure.core", "vals");
		CONTAINS = RT.var("clojure.core", "contains?");
		REDUCE = RT.var("clojure.core", "reduce");
		INTERSECTION = RT.var("clojure.set", "intersection");
		UNION = RT.var("clojure.set", "union");
		DIFFERENCE = RT.var("clojure.set", "difference");
	}

	private PersistentHashMap map;

	public BRelation(PersistentHashMap map) {
		this.map = map;
	}

	@SafeVarargs
	public BRelation(BTuple<S,T>... elements) {
		this.map = PersistentHashMap.EMPTY;
		for(BTuple<S,T> e : elements) {
			S key = e.projection1();
			T value = e.projection2();
			PersistentHashSet set = (PersistentHashSet) GET.invoke(this.map, key);
			if(set == null) {
				set = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(value)));
			} else {
				set = (PersistentHashSet) UNION.invoke(set, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(value))));
			}
			this.map = (PersistentHashMap) ASSOC.invoke(this.map, key, set);
		}
	}

	public static <S,T> BRelation<S,T> fromSet(BSet<BTuple<S,T>> set) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(BTuple<S,T> e : set) {
			S key = e.projection1();
			T value = e.projection2();
			PersistentHashSet range = (PersistentHashSet) GET.invoke(resultMap, key);
			if(set == null) {
				range = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(value)));
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, key, range);
			} else {
				range = (PersistentHashSet) UNION.invoke(range, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(value))));
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, key, range);
			}
		}
		return new BRelation<S,T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		BRelation<S,T> bObjects = (BRelation<S,T>) o;

		if (!map.equals(bObjects.map))
			return false;

		return true;
	}

	public int hashCode() {
		return Objects.hash(map);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> intersect(BRelation<S,T> relation) {
		PersistentHashMap otherMap = relation.map;
		PersistentHashSet otherDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(otherMap));
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
		PersistentHashSet intersectionDomain = (PersistentHashSet) INTERSECTION.invoke(thisDomain, otherDomain);
		PersistentHashSet differenceDomain = (PersistentHashSet) DIFFERENCE.invoke(thisDomain, otherDomain);

		PersistentHashMap resultMap = this.map;
		for(Object obj : intersectionDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			PersistentHashSet otherRangeSet = (PersistentHashSet) GET.invoke(otherMap, domainElement);
			PersistentHashSet newRangeSet = (PersistentHashSet) INTERSECTION.invoke(thisRangeSet, otherRangeSet);
			if(newRangeSet.isEmpty()) {
				resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, domainElement);
			} else {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, newRangeSet);
			}
		}

		for(Object obj : differenceDomain) {
			S domainElement = (S) obj;
			resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, domainElement);
		}
		return new BRelation<S,T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> difference(BRelation<S,T> relation) {
		PersistentHashMap otherMap = relation.map;
		PersistentHashSet otherDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(otherMap));
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
		PersistentHashSet intersectionDomain = (PersistentHashSet) INTERSECTION.invoke(thisDomain, otherDomain);

		PersistentHashMap resultMap = this.map;
		for(Object obj : intersectionDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			PersistentHashSet otherRangeSet = (PersistentHashSet) GET.invoke(otherMap, domainElement);
			if(otherRangeSet == null) {
				continue;
			}
			PersistentHashSet newRangeSet = (PersistentHashSet) DIFFERENCE.invoke(thisRangeSet, otherRangeSet);

			if(newRangeSet.isEmpty()) {
				resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, domainElement);
			} else {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, newRangeSet);
			}
		}
		return new BRelation<S,T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> union(BRelation<S,T> relation) {
		PersistentHashMap otherMap = relation.map;
		PersistentHashSet otherDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(otherMap));

		PersistentHashMap resultMap = this.map;
		for(Object obj : otherDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			PersistentHashSet otherRangeSet = (PersistentHashSet) GET.invoke(otherMap, domainElement);
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, UNION.invoke(thisRangeSet, otherRangeSet));
		}
		return new BRelation<S,T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public int size() {
		int size = 0;
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		for(Object obj : thisDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			size += thisRangeSet.size();
		}
		return size;
	}

	public BInteger card() {
		return new BInteger(String.valueOf((int) this.size()));
	}

	public BInteger _size() {
		return new BInteger(String.valueOf((int) this.size()));
	}

	public BBoolean equal(BRelation<S,T> o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BRelation<S,T> o) {
		return new BBoolean(!equals(o));
	}

	public BBoolean elementOf(BTuple<S,T> object) {
		S prj1 = object.projection1();
		T prj2 = object.projection2();

		PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, prj1);

		if(range == null) {
			return new BBoolean(false);
		}

		return new BBoolean(range.contains(prj2));
	}

	public BBoolean notElementOf(BTuple<S,T> object) {
		S prj1 = object.projection1();
		T prj2 = object.projection2();

		PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, prj1);

		if(range == null) {
			return new BBoolean(true);
		}

		return new BBoolean(!range.contains(prj2));
	}

	@SuppressWarnings("unchecked")
	public BSet<T> relationImage(BSet<S> domain) {
		PersistentHashSet resultSet = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke()));
		for(S domainElement: domain) {
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			if(thisRangeSet == null) {
				continue;
			}
			resultSet = (PersistentHashSet) UNION.invoke(resultSet, thisRangeSet);
		}
		return new BSet<T>(resultSet);
	}


	@SuppressWarnings("unchecked")
	public T functionCall(S arg) {
		PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, arg);
		if(range == null) {
			throw new RuntimeException("Argument is not in the domain of this relation");
		}
		for(Object element : range) {
			return (T) element;
		}
		throw new RuntimeException("Argument is not in the domain of this relation");
	}

	@SuppressWarnings("unchecked")
	public BSet<BRelation<S,T>> pow() {
		PersistentHashMap thisMap = this.map;
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(thisMap));


		BSet<BRelation<S,T>> result = new BSet<BRelation<S,T>>();
		BRelation<S,T> start = new BRelation<>();
		Queue<BRelation<S,T>> queue = new LinkedList<>();
		queue.add(start);
		result = result.union(new BSet<BRelation<S,T>>(start));
		while(!queue.isEmpty()) {
			BRelation<S,T> currentSet = queue.remove();

			for(Object e1 : thisDomain) {
				S domainElement = (S) e1;
				PersistentHashSet range = (PersistentHashSet) GET.invoke(thisMap, domainElement);
				if(range == null) {
					break;
				}
				for(Object e2 : range) {
					T rangeElement = (T) e2;
					BRelation<S,T> nextRelation = currentSet.union(BRelation.fromSet(new BSet(new BTuple<S,T>(domainElement, rangeElement))));
					int previousSize = result.size();
					result = result.union(new BSet<BRelation<S,T>>(nextRelation));
					if(previousSize < result.size()) {
						queue.add(nextRelation);
					}
				}
			}
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BSet<BRelation<S,T>> pow1() {
		return this.pow().difference(new BSet<BRelation<S,T>>(new BRelation<S,T>()));
	}

	public BSet<BRelation<S,T>> fin() {
		return this.pow();
	}

	public BSet<BRelation<S,T>> fin1() {
		return this.pow1();
	}

	@SuppressWarnings("unchecked")
	public BSet<S> domain() {
		PersistentHashMap thisMap = this.map;
		PersistentHashSet set = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
		PersistentHashSet resultSet = set;
		for(Object obj : set) {
			S domainElement = (S) obj;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(thisMap, domainElement);
			if(range == null || range.size() == 0) {
				resultSet = (PersistentHashSet) DIFFERENCE.invoke(resultSet, SET.invoke(SEQ.invoke(LIST.invoke(domainElement))));
			}
		}
		return new BSet<S>(resultSet);
	}

	@SuppressWarnings("unchecked")
	public BRelation domainForRelations() {
		BRelation result = new BRelation();
		for(S elem : this.domain()) {
			result = result.union(new BRelation((BTuple) elem));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BSet<T> range() {
		PersistentHashSet set = (PersistentHashSet) REDUCE.invoke(UNION, SET.invoke(SEQ.invoke(LIST.invoke())), VALS.invoke(this.map));
		return new BSet<T>(set);
	}

	@SuppressWarnings("unchecked")
	public BRelation rangeForRelations() {
		BRelation result = new BRelation();
		for(T elem : this.range()) {
			result = result.union(new BRelation((BTuple) elem));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<T,S> inverse() {
		PersistentHashMap thisMap = this.map;
		PersistentHashSet keys = (PersistentHashSet) SET.invoke(KEYS.invoke(thisMap));

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : keys) {
			S domainElement = (S) e1;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(thisMap, domainElement);
			if(range == null) {
				break;
			}
			for(Object e2 : range) {
				T rangeElement = (T) e2;
				PersistentHashSet currentRange = (PersistentHashSet) GET.invoke(resultMap, rangeElement);
				if(currentRange == null) {
					currentRange = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke()));
				}
				currentRange = (PersistentHashSet) UNION.invoke(currentRange, SET.invoke(SEQ.invoke(LIST.invoke(domainElement))));
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, rangeElement, currentRange);
			}
		}
		return new BRelation<T, S>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> domainRestriction(BSet<S> arg) {
		PersistentHashSet set = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
		PersistentHashSet otherSet = arg.getSet();
		PersistentHashSet resultSet = (PersistentHashSet) DIFFERENCE.invoke(set, otherSet);
		PersistentHashMap resultMap = this.map;
		for(Object obj : resultSet) {
			resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, obj);
		}
		return new BRelation<S,T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> domainSubstraction(BSet<S> arg) {
		PersistentHashSet set = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
		PersistentHashSet otherSet = arg.getSet();
		PersistentHashMap resultMap = this.map;
		for(Object obj : otherSet) {
			resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, obj);
		}
		return new BRelation<S,T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> rangeRestriction(BSet<T> arg) {
		PersistentHashSet otherSet = (PersistentHashSet) arg.getSet();
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		PersistentHashMap resultMap = this.map;
		for(Object obj : thisDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			PersistentHashSet newRangeSet = (PersistentHashSet) INTERSECTION.invoke(thisRangeSet, otherSet);
			if(newRangeSet.isEmpty()) {
				resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, domainElement);
			} else {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, newRangeSet);
			}
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> rangeSubstraction(BSet<T> arg) {
		PersistentHashSet otherSet = (PersistentHashSet) arg.getSet();
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		PersistentHashMap resultMap = this.map;
		for(Object obj : thisDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			PersistentHashSet newRangeSet = (PersistentHashSet) DIFFERENCE.invoke(thisRangeSet, otherSet);
			if(newRangeSet.isEmpty()) {
				resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, domainElement);
			} else {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, newRangeSet);
			}
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BBoolean subset(BRelation<S,T> arg) {
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		for(Object obj : thisDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			PersistentHashSet otherRangeSet = (PersistentHashSet) GET.invoke(arg.map, domainElement);
			if(thisRangeSet != null) {
				if(otherRangeSet == null) {
					return new BBoolean(false);
				}
				if(!thisRangeSet.isEmpty() && !otherRangeSet.containsAll(thisRangeSet)) {
					return new BBoolean(false);
				}
			}
		}
		return new BBoolean(true);
	}

	@SuppressWarnings("unchecked")
	public BBoolean notSubset(BRelation<S,T> arg) {
		return subset(arg).not();
	}

	public BBoolean strictSubset(BRelation<S,T> set) {
		return new BBoolean(set.size() != this.size() && this.subset(set).booleanValue());
	}

	public BBoolean strictNotSubset(BRelation<S, T> set) {
		return new BBoolean(set.size() == this.size() || !this.subset(set).booleanValue());
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> override(BRelation<S,T> arg) {
		PersistentHashMap otherMap = arg.map;

		PersistentHashSet otherDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(otherMap));

		PersistentHashMap resultMap = this.map;
		for(Object obj : otherDomain) {
			S domainElement = (S) obj;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(otherMap, domainElement);
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, range);
		}

		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public T first() {
		return this.functionCall((S) new BInteger("1"));
	}

	@SuppressWarnings("unchecked")
	public T last() {
		return this.functionCall((S) this.card());
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> reverse() {
		BInteger size = this.card();
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(BInteger i = new BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
			T rangeElement = (T) this.functionCall((S) size.minus(i).succ());
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, i, SET.invoke(SEQ.invoke(LIST.invoke(rangeElement))));
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> front() {
		return this.domainSubstraction(new BSet<>((S) this.card()));
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> tail() {
		BInteger size = this._size();
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(BInteger i = new BInteger("2"); i.lessEqual(size).booleanValue(); i = i.succ()) {
			T rangeElement = (T) this.functionCall((S) i);
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, i.pred(), SET.invoke(SEQ.invoke(LIST.invoke(rangeElement))));
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> take(BInteger n) {
		BInteger size = this._size();
		if(n.greaterEqual(size).booleanValue()) {
			return new BRelation<S, T>(this.map);
		}
		PersistentHashMap resultMap = this.map;
		//Remove sets with index greater than n
		for(BInteger i = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
			resultMap = (PersistentHashMap) DISSOC.invoke(resultMap, i);
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> drop(BInteger n) {
		BInteger size = this._size();
		PersistentHashMap thisMap = this.map;
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(BInteger i = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
			PersistentHashSet currentSet = (PersistentHashSet) GET.invoke(thisMap, i);
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, i.minus(n), currentSet);
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> concat(BRelation<S,T> arg) {
		PersistentHashMap resultMap = this.map;
		PersistentHashMap otherMap = arg.map;
		BInteger size = this.card();
		for(BInteger i = new BInteger("1"); i.lessEqual(arg._size()).booleanValue(); i = i.succ()) {
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, size.plus(i), (PersistentHashSet) GET.invoke(otherMap, i));
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public <R,A> T conc() {
		BRelation<R,A> result = new BRelation<R,A>();
		BInteger size = this.card();
		for(BInteger i = new BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
			result = result.concat((BRelation<R,A>) functionCall((S) i));
		}
		return (T) result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> append(T arg) {
		PersistentHashMap resultMap = this.map;
		resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, this.card().succ(), (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(arg))));
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> prepend(T arg) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		PersistentHashMap thisMap = this.map;
		BInteger size = this._size();
		for(BInteger i = new BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, i.succ(), (PersistentHashSet) GET.invoke(thisMap, i));
		}
		resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, new BInteger("1"), (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(arg))));
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public <R> BRelation<S,BTuple<T,R>> directProduct(BRelation<S,R> arg) {
		PersistentHashMap thisMap = (PersistentHashMap) this.map;
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(thisMap));
		PersistentHashMap otherMap = (PersistentHashMap) arg.map;

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object obj : thisDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRange = (PersistentHashSet) GET.invoke(thisMap, domainElement);
			PersistentHashSet otherRange = (PersistentHashSet) GET.invoke(otherMap, domainElement);
			if(otherRange == null) {
				continue;
			}
			PersistentHashSet resultRange = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke()));
			for(Object lhs : thisRange) {
				for(Object rhs : otherRange) {
					T lhsElement = (T) lhs;
					R rhsElement = (R) rhs;
					resultRange = (PersistentHashSet) UNION.invoke(resultRange, SET.invoke(SEQ.invoke(LIST.invoke(new BTuple<T,R>(lhsElement, rhsElement)))));
				}
			}
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, resultRange);
		}
		return new BRelation<S, BTuple<T, R>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public <R,A> BRelation<BTuple<S,R>,BTuple<T,A>> parallelProduct(BRelation<R,A> arg) {
		PersistentHashMap thisMap = (PersistentHashMap) this.map;
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(thisMap));

		PersistentHashMap otherMap = (PersistentHashMap) arg.map;
		PersistentHashSet otherDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(otherMap));

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;

		for(Object domainElementThis : thisDomain) {
			for(Object domaineElementOther : otherDomain) {
				S domainElementThisElement = (S) domainElementThis;
				R domainElementOtherElement = (R) domaineElementOther;

				PersistentHashSet thisRange = (PersistentHashSet) GET.invoke(thisMap, domainElementThisElement);
				PersistentHashSet otherRange = (PersistentHashSet) GET.invoke(otherMap, domainElementOtherElement);

				PersistentHashSet resultRange = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke()));
				for(Object lhs : thisRange) {
					for(Object rhs : otherRange) {
						T lhsElement = (T) lhs;
						A rhsElement = (A) rhs;
						resultRange = (PersistentHashSet) UNION.invoke(resultRange, SET.invoke(SEQ.invoke(LIST.invoke(new BTuple<T,A>(lhsElement, rhsElement)))));
					}
				}
				BTuple<S,R> tuple = new BTuple<S,R>(domainElementThisElement, domainElementOtherElement);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, resultRange);
			}
		}
		return new BRelation<BTuple<S, R>, BTuple<T, A>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public <R> BRelation<S,R> composition(BRelation<T,R> arg) {
		PersistentHashMap thisMap = this.map;
		PersistentHashMap otherMap = arg.map;

		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(thisMap));

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;

		for(Object e1 : thisDomain) {
			S domainElement = (S) e1;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(thisMap, domainElement);

			PersistentHashSet set = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke()));
			if(range == null) {
				break;
			}
			for(Object e2: range) {
				T rangeElement = (T) e2;
				set = (PersistentHashSet) UNION.invoke(set, (PersistentHashSet) GET.invoke(otherMap, rangeElement));
			}
			if(set.isEmpty()) {
				continue;
			}
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, set);
		}
		return new BRelation<S, R>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> iterate(BInteger n) {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = (BRelation<S,S>) this;
		for(BInteger i = new BInteger(2); i.lessEqual(n).booleanValue(); i = i.succ()) {
			result = result.composition(thisRelation);
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> closure() {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = identity(this.domain().union(thisRelation.range()));
		BRelation<S,S> nextResult = result.composition(thisRelation);
		BRelation<S,S> lastResult = null;
		do {
			lastResult = result;
			result = result.union(nextResult);
			nextResult = result.composition(thisRelation);
		} while(!result.equal(lastResult).booleanValue());
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> closure1() {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = (BRelation<S,S>) this;
		BRelation<S,S> nextResult = result.composition(thisRelation);
		BRelation<S,S> lastResult = null;
		do {
			lastResult = result;
			result = result.union(nextResult);
			nextResult = result.composition(thisRelation);
		} while(!result.equal(lastResult).booleanValue());
		return result;
	}

	public BBoolean isInClosure(BTuple<S,S> tuple) {
		S projection1 = tuple.projection1();
		S projection2 = tuple.projection2();
		if(projection1.equals(projection2)) {
			PersistentHashSet imageOfProjection1 = (PersistentHashSet) GET.invoke(this.map, projection1);
			if(imageOfProjection1 != null && !imageOfProjection1.isEmpty()) {
				return new BBoolean(true);
			}
			PersistentHashSet keys = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
			for (Object key : keys) {
				PersistentHashSet image = (PersistentHashSet) GET.invoke(this.map, key);
				if(image != null && image.contains(projection2)) {
					return new BBoolean(true);
				}
			}
		}
		return isInClosure1(tuple);
	}

	public BBoolean isNotInClosure(BTuple<S,S> tuple) {
		return isInClosure(tuple).not();
	}

	@SuppressWarnings("unchecked")
	public BBoolean isInClosure1(BTuple<S,S> tuple) {
		BBoolean inThisRelation = this.elementOf((BTuple<S, T>) tuple);
		if(inThisRelation.booleanValue()) {
			return inThisRelation;
		}
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = (BRelation<S,S>) this;
		BRelation<S,S> nextResult = result.composition(thisRelation);
		BRelation<S,S> lastResult = null;
		do {
			inThisRelation = nextResult.elementOf(tuple);
			if(inThisRelation.booleanValue()) {
				return inThisRelation;
			}
			lastResult = result;
			result = result.union(nextResult);
			nextResult = result.composition(thisRelation);
		} while(!result.equal(lastResult).booleanValue());
		return new BBoolean(false);
	}

	public BBoolean isNotInClosure1(BTuple<S,S> tuple) {
		return isInClosure1(tuple).not();
	}

	@SuppressWarnings("unchecked")
	public static <S,T> BRelation<BTuple<S,T>, S> projection1(BSet<S> arg1, BSet<T> arg2) {
		PersistentHashSet argSet1 = (PersistentHashSet) arg1.getSet();
		PersistentHashSet argSet2 = (PersistentHashSet) arg2.getSet();

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : argSet1) {
			for(Object e2 : argSet2) {
				S element1 = (S) e1;
				T element2 = (T) e2;

				BTuple<S,T> tuple = new BTuple<S,T>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element1))));
			}
		}
		return new BRelation<BTuple<S, T>, S>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R> BRelation<BTuple<S,BTuple<T,R>>, S> projection1(BSet<S> arg1, BRelation<T,R> arg2) {

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : arg1) {
			for(Object e2 : arg2) {
				S element1 = (S) e1;
				BTuple<T,R> element2 = (BTuple<T,R>) e2;

				BTuple<S,BTuple<T,R>> tuple = new BTuple<S,BTuple<T,R>>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element1))));
			}
		}
		return new BRelation<BTuple<S,BTuple<T,R>>, S>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R> BRelation<BTuple<BTuple<S,T>,R>, BTuple<S,T>> projection1(BRelation<S,T> arg1, BSet<R> arg2) {

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : arg1) {
			for(Object e2 : arg2) {
				BTuple<S,T> element1 = (BTuple<S,T>) e1;
				R element2 = (R) e2;

				BTuple<BTuple<S,T>,R> tuple = new BTuple<BTuple<S,T>,R>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element1))));
			}
		}
		return new BRelation<BTuple<BTuple<S,T>,R>, BTuple<S,T>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R,A> BRelation<BTuple<BTuple<S,T>,BTuple<R,A>>, BTuple<S,T>> projection1(BRelation<S,T> arg1, BRelation<R,A> arg2) {

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : arg1) {
			for(Object e2 : arg2) {
				BTuple<S,T> element1 = (BTuple<S,T>) e1;
				BTuple<R,A> element2 = (BTuple<R,A>) e2;

				BTuple<BTuple<S,T>,BTuple<R,A>> tuple = new BTuple<BTuple<S,T>,BTuple<R,A>>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element1))));
			}
		}
		return new BRelation<BTuple<BTuple<S,T>,BTuple<R,A>>, BTuple<S,T>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T> BRelation<BTuple<S,T>, T> projection2(BSet<S> arg1, BSet<T> arg2) {
		PersistentHashSet argSet1 = (PersistentHashSet) arg1.getSet();
		PersistentHashSet argSet2 = (PersistentHashSet) arg2.getSet();

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : argSet1) {
			for(Object e2 : argSet2) {
				S element1 = (S) e1;
				T element2 = (T) e2;

				BTuple<S,T> tuple = new BTuple<S,T>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element2))));
			}
		}
		return new BRelation<BTuple<S, T>, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R> BRelation<BTuple<S,BTuple<T,R>>, BTuple<T,R>> projection2(BSet<S> arg1, BRelation<T,R> arg2) {

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : arg1) {
			for(Object e2 : arg2) {
				S element1 = (S) e1;
				BTuple<T,R> element2 = (BTuple<T,R>) e2;

				BTuple<S,BTuple<T,R>> tuple = new BTuple<S,BTuple<T,R>>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element2))));
			}
		}
		return new BRelation<BTuple<S,BTuple<T,R>>, BTuple<T,R>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R> BRelation<BTuple<BTuple<S,T>,R>, R> projection2(BRelation<S,T> arg1, BSet<R> arg2) {

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : arg1) {
			for(Object e2 : arg2) {
				BTuple<S,T> element1 = (BTuple<S,T>) e1;
				R element2 = (R) e2;

				BTuple<BTuple<S,T>,R> tuple = new BTuple<BTuple<S,T>,R>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element2))));
			}
		}
		return new BRelation<BTuple<BTuple<S,T>,R>, R>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R,A> BRelation<BTuple<BTuple<S,T>,BTuple<R,A>>, BTuple<R,A>> projection2(BRelation<S,T> arg1, BRelation<R,A> arg2) {

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : arg1) {
			for(Object e2 : arg2) {
				BTuple<S,T> element1 = (BTuple<S,T>) e1;
				BTuple<R,A> element2 = (BTuple<R,A>) e2;

				BTuple<BTuple<S,T>,BTuple<R,A>> tuple = new BTuple<BTuple<S,T>,BTuple<R,A>>(element1, element2);
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, tuple, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(element2))));
			}
		}
		return new BRelation<BTuple<BTuple<S,T>,BTuple<R,A>>, BTuple<R,A>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,BSet<T>> fnc() {
		PersistentHashMap thisMap = this.map;
		PersistentHashSet domain = this.domain().getSet();

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e : domain) {
			S domainElement = (S) e;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(thisMap, e);
			BSet<T> rangeSet = new BSet<T>(range);
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke(rangeSet))));
		}
		return new BRelation<S, BSet<T>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation rel() {
		BSet<S> domain = this.domain();

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(S domainElement : domain) {
			BSet range = (BSet) this.functionCall(domainElement);
			PersistentHashSet rangeSet = range.getSet();
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, rangeSet);
		}
		return new BRelation(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <T> BRelation<T,T> identity(BSet<T> arg) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(T e : arg) {
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, e, SET.invoke(SEQ.invoke(LIST.invoke(e))));
		}
		return new BRelation<T, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T> BRelation<BTuple<S,T>,BTuple<S,T>> identity(BRelation<S,T> arg) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(BTuple<S,T> e : arg) {
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, e, SET.invoke(SEQ.invoke(LIST.invoke(e))));
		}
		return new BRelation<BTuple<S,T>,BTuple<S,T>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T> BRelation<S,T> cartesianProduct(BSet<S> arg1, BSet<T> arg2) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(S e1 : arg1) {
			if(!arg2.getSet().isEmpty()) {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, e1, arg2.getSet());
			}
		}
		return new BRelation<S, T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R> BRelation<S,BTuple<T,R>> cartesianProduct(BSet<S> arg1, BRelation<T,R> arg2) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(S e1 : arg1) {
			PersistentHashSet rangeSet = PersistentHashSet.EMPTY;
			for(BTuple<T,R> e2 : arg2) {
				rangeSet = (PersistentHashSet) UNION.invoke(rangeSet, SET.invoke(SEQ.invoke(LIST.invoke(e2))));
			}
			if(!rangeSet.isEmpty()) {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, e1, rangeSet);
			}
		}
		return new BRelation<S,BTuple<T,R>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R> BRelation<BTuple<S,T>, R> cartesianProduct(BRelation<S,T> arg1, BSet<R> arg2) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(BTuple<S,T> e1 : arg1) {
			if(!arg2.getSet().isEmpty()) {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, e1, arg2.getSet());
			}
		}
		return new BRelation<>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public static <S,T,R,A> BRelation<BTuple<S,T>,BTuple<R,A>> cartesianProduct(BRelation<S,T> arg1, BRelation<R,A> arg2) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(BTuple<S,T> e1 : arg1) {
			PersistentHashSet rangeSet = PersistentHashSet.EMPTY;
			for(BTuple<R,A> e2 : arg2) {
				rangeSet = (PersistentHashSet) UNION.invoke(rangeSet, SET.invoke(SEQ.invoke(LIST.invoke(e2))));
			}
			if(!rangeSet.isEmpty()) {
				resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, e1, rangeSet);
			}
		}
		return new BRelation<BTuple<S,T>,BTuple<R,A>>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BTuple<S,T> nondeterminism(int index) {
		int size = this.size();
		if(index >= size) {
			return null;
		}
		PersistentHashMap thisMap = this.map;
		PersistentHashSet domain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		int i = 0;
		for(Object domObj : domain) {
			PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, (S) domObj);
			for(Object rangeObj : range) {
				if(i == index) {
					return new BTuple<S,T>((S) domObj, (T) rangeObj);
				}
				i++;
			}
		}
		return null;
	}

	@SuppressWarnings("unchecked")
	public BTuple<S,T> nondeterminism() {
		PersistentHashMap thisMap = this.map;
		PersistentHashSet domain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		int index = (int) Math.floor(Math.random() * domain.size());
		int i = 0;
		S domainElement = null;
		for(Object obj : domain) {
			if(i == index) {
				domainElement = (S) obj;
				break;
			}
			i++;
		}

		PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, domainElement);
		index = (int) Math.floor(Math.random() * range.size());
		i = 0;
		if(range == null) {
			return null;
		}
		for(Object obj : range) {
			if(i == index) {
				return new BTuple<S,T>(domainElement, (T) obj);
			}
			i++;
		}
		return null;
	}

	public BBoolean isTotal(BSet<S> domain) {
		return this.domain().equal(domain);
	}

	@SuppressWarnings("unchecked")
	public <R1, R2> BBoolean isTotal(BRelation<R1, R2> domain) {
		BSet<BTuple<R1, R2>> domainAsSet = new BSet<BTuple<R1, R2>>();
		for(BTuple<R1, R2> tuple: domain) {
			domainAsSet = domainAsSet.union(new BSet<>(tuple));
		}
		return this.domain().equal((BSet<S>) domainAsSet);
	}

	@SuppressWarnings("unchecked")
	public BBoolean isTotalBoolean() {
		return ((BSet<BBoolean>) this.domain()).equal(BUtils.BOOL);
	}

	public BBoolean isTotalInteger() {
		return new BBoolean(false);
	}

	public BBoolean isTotalNatural() {
		return new BBoolean(false);
	}

	public BBoolean isTotalNatural1() {
		return new BBoolean(false);
	}

	public BBoolean isTotalString() {
		return new BBoolean(false);
	}

	public BBoolean isTotalStruct() {
		return new BBoolean(false);
	}

	public BBoolean isPartial(BSet<S> domain) {
		return this.domain().subset(domain);
	}

	@SuppressWarnings("unchecked")
	public <A1,A2> BBoolean isPartial(BRelation<A1, A2> domain) {
		for(S element : this.domain()) {
			BTuple<A1, A2> elementAsTuple = (BTuple<A1, A2>) element;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(domain.map, elementAsTuple.projection1());
			if(range == null) {
				return new BBoolean(false);
			}
			if(!range.contains(elementAsTuple.projection2())) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isPartialBoolean() {
		for(S e : this.domain()) {
			if(e instanceof BBoolean) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isPartialInteger() {
		for(S e : this.domain()) {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isPartialNatural() {
		for(S e : this.domain()) {
			if(e instanceof BInteger && !((BInteger)e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isPartialNatural1() {
		for(S e : this.domain()) {
			if(e instanceof BInteger && !((BInteger)e).isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isPartialString() {
		for(S e : this.domain()) {
			if(e instanceof BString && !((BString) e).isString().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isPartialStruct() {
		for(S e : this.domain()) {
			if(e instanceof BStruct && !((BStruct) e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkDomain(BSet<S> domain) {
		return this.domain().subset(domain);
	}

	@SuppressWarnings("unchecked")
	public <A1,A2> BBoolean checkDomain(BRelation<A1, A2> domain) {
		for(S element : this.domain()) {
			BTuple<A1, A2> elementAsTuple = (BTuple<A1, A2>) element;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(domain.map, elementAsTuple.projection1());
			if(range == null) {
				return new BBoolean(false);
			}
			if(!range.contains(elementAsTuple.projection2())) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkDomainBoolean() {
		for(S e : this.domain()) {
			if(e instanceof BBoolean) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkDomainInteger() {
		for(S e : this.domain()) {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkDomainNatural() {
		for(S e : this.domain()) {
			if(e instanceof BInteger && !((BInteger) e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkDomainNatural1() {
		for(S e : this.domain()) {
			if(e instanceof BInteger && !((BInteger) e).isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkDomainString() {
		for(S e : this.domain()) {
			if(e instanceof BString && !((BString) e).isString().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkDomainStruct() {
		for(S e : this.domain()) {
			if(e instanceof BStruct && !((BStruct) e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkRange(BSet<T> range) {
		return this.range().subset(range);
	}

	@SuppressWarnings("unchecked")
	public <A1,A2> BBoolean checkRange(BRelation<A1, A2> range) {
		for(T element : this.range()) {
			BTuple<A1, A2> elementAsTuple = (BTuple<A1, A2>) element;
			PersistentHashSet rangeRange = (PersistentHashSet) GET.invoke(range.map, elementAsTuple.projection1());
			if(rangeRange == null) {
				return new BBoolean(false);
			}
			if(!rangeRange.contains(elementAsTuple.projection2())) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkRangeInteger() {
		for(T e : this.range()) {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkRangeBoolean() {
		for(T e : this.range()) {
			if(e instanceof BBoolean) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkRangeNatural() {
		for(T e : this.range()) {
			if(e instanceof BInteger && !((BInteger) e).isNatural().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkRangeNatural1() {
		for(T e : this.range()) {
			if(e instanceof BInteger && !((BInteger) e).isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkRangeString() {
		for(T e : this.range()) {
			if(e instanceof BString && !((BString) e).isString().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean checkRangeStruct() {
		for(T e : this.range()) {
			if(e instanceof BStruct && !((BStruct) e).isRecord().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isRelation() {
		return new BBoolean(true);
	}

	public BBoolean isFunction() {
		for(S element : this.domain()) {
			PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, element);
			if(range.size() > 1) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isSurjection(BSet<T> range) {
		return this.range().equal(range);
	}

	public BBoolean isSurjectionInteger() {
		return new BBoolean(false);
	}

	public BBoolean isSurjectionNatural() {
		return new BBoolean(false);
	}

	public BBoolean isSurjectionNatural1() {
		return new BBoolean(false);
	}

	public BBoolean isSurjectionString() {
		return new BBoolean(false);
	}

	public BBoolean isSurjectionStruct() {
		return new BBoolean(false);
	}

	@SuppressWarnings("unchecked")
	public BBoolean isInjection() {
		PersistentHashSet visited = (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke()));
		for(S element : this.domain()) {
			PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, element);
			if(range == null) {
				break;
			}
			for(Object e : range) {
				T rangeElement = (T) e;
				if(visited.contains(rangeElement)) {
					return new BBoolean(false);
				}
				visited = (PersistentHashSet) UNION.invoke(visited, SET.invoke(SEQ.invoke(LIST.invoke(rangeElement))));
			}
		}
		return new BBoolean(true);
	}

	public BBoolean isBijection(BSet<T> range) {
		return isSurjection(range).and(isInjection());
	}

	public BBoolean isBijectionInteger() {
		return new BBoolean(false);
	}

	public BBoolean isBijectionNatural() {
		return new BBoolean(false);
	}

	public BBoolean isBijectionNatural1() {
		return new BBoolean(false);
	}

	public BBoolean isBijectionString() {
		return new BBoolean(false);
	}

	public BBoolean isBijectionStruct() {
		return new BBoolean(false);
	}

	public BBoolean isInDomain(S element) {
		return new BBoolean(this.map.containsKey(element));
	}

	public BBoolean isNotInDomain(S element) {
		return isInDomain(element).not();
	}

	public BBoolean isInRange(T element) {
		PersistentHashSet keys = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
		for (Object key : keys) {
			PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, key);
			if(range != null && range.contains(element)) {
				return new BBoolean(true);
			}
		}
		return new BBoolean(false);
	}

	public BBoolean isNotInRange(T element) {
		return isInRange(element).not();
	}

	public BBoolean isInRelationalImage(T element, BSet<S> set) {
		for (S key : set) {
			PersistentHashSet image = (PersistentHashSet) GET.invoke(this.map, key);
			if(image != null && image.contains(element)) {
				return new BBoolean(true);
			}
		}
		return new BBoolean(false);
	}

	public BBoolean isNotInRelationalImage(T element, BSet<S> set) {
		return isNotInRelationalImage(element, set).not();
	}

	public <R> BBoolean isInComposition(BTuple<S,R> tuple, BRelation<T,R> arg) {
		S projection1 = tuple.projection1();
		R projection2 = tuple.projection2();

		PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, projection1);

		if(range != null) {
			for (Object value : range) {
				PersistentHashSet range2 = (PersistentHashSet) GET.invoke(arg.map, value);
				if (range2 != null && range2.contains(projection2)) {
					return new BBoolean(true);
				}
			}
		}
		return new BBoolean(false);
	}

	public <R> BBoolean isNotInComposition(BTuple<S,R> tuple, BRelation<T,R> arg) {
		return isInComposition(tuple, arg).not();
	}

	@SuppressWarnings("unchecked")
	@Override
	public Iterator<BTuple<S,T>> iterator() {
		PersistentHashMap thisMap = this.map;


		return new Iterator<BTuple<S, T>>() {

			final Iterator<S> keyIterator = thisMap.keyIterator();
			S currentLhs = keyIterator.hasNext() ? keyIterator.next() : null;
			Iterator<T> valueIterator = currentLhs == null ? null : ((PersistentHashSet) thisMap.get(currentLhs)).iterator();

			@Override
			public boolean hasNext() {
				if(keyIterator == null) {
					return false;
				}
				if(keyIterator.hasNext()) {
					return true;
				}
				if(valueIterator == null) {
					return false;
				}
				return valueIterator.hasNext();
			}

			@SuppressWarnings("unchecked")
			@Override
			public BTuple<S, T> next() {
				// If there is no next key, then we have already iterated through the relation
				if(currentLhs == null) {
					return null;
				}

				if(valueIterator == null || !valueIterator.hasNext()) {
					currentLhs = keyIterator.next();
					valueIterator = currentLhs == null ? null : ((PersistentHashSet) thisMap.get(currentLhs)).iterator();
				}

				if(currentLhs == null || !valueIterator.hasNext()) {
					return null;
				}

				return new BTuple<S,T>(currentLhs, valueIterator.next());
			}
		};
	}

	@SuppressWarnings("unchecked")
	public java.lang.String toString() {

		PersistentHashMap thisMap = this.map;
		PersistentHashSet domain = (PersistentHashSet) SET.invoke(KEYS.invoke(thisMap));

		int size = this.size();
		int i = 0;

		StringBuffer sb = new StringBuffer();
		sb.append("{");
		for(Object e1 : domain) {
			S domainElement = (S) e1;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(thisMap, domainElement);
			if(range == null) {
				break;
			}
			for(Object e2 : range) {
				T rangeElement = (T) e2;
				sb.append("(");
				sb.append(domainElement.toString());
				sb.append(" |-> ");
				sb.append(rangeElement.toString());
				sb.append(")");
				if (i+1 < size) {
					sb.append(", ");
				}
				i++;
			}
		}
		sb.append("}");
		return sb.toString();
	}
}
