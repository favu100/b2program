package de.hhu.stups.btypes;

import clojure.java.api.Clojure;
import clojure.lang.PersistentHashSet;
import clojure.lang.PersistentHashMap;
import clojure.lang.RT;
import clojure.lang.Var;

import java.util.Iterator;
import java.util.Set;
import java.util.LinkedList;
import java.util.Queue;
import java.util.stream.Collectors;

/**
 * Created by fabian on 15.01.19.
 */
public class BRelation<S,T> {

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
		return map.hashCode();
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
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, INTERSECTION.invoke(thisRangeSet, otherRangeSet));
		}

		for(Object obj : differenceDomain) {
			S domainElement = (S) obj;
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke())));
		}
		return new BRelation<S,T>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> difference(BRelation<S,T> relation) {
		PersistentHashMap otherMap = relation.map;
		PersistentHashSet otherDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(otherMap));
		PersistentHashSet thisDomain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));
		PersistentHashSet differenceDomain = (PersistentHashSet) DIFFERENCE.invoke(thisDomain, otherDomain);
		PersistentHashSet restDomain = (PersistentHashSet) DIFFERENCE.invoke(thisDomain, differenceDomain);

		PersistentHashMap resultMap = this.map;
		for(Object obj : differenceDomain) {
			S domainElement = (S) obj;
			PersistentHashSet thisRangeSet = (PersistentHashSet) GET.invoke(this.map, domainElement);
			PersistentHashSet otherRangeSet = (PersistentHashSet) GET.invoke(otherMap, domainElement);
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, DIFFERENCE.invoke(thisRangeSet, otherRangeSet));
		}

		for(Object obj : restDomain) {
			S domainElement = (S) obj;
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, (PersistentHashSet) SET.invoke(SEQ.invoke(LIST.invoke())));
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

		PersistentHashSet domain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		if(!domain.contains(prj1)) {
			return new BBoolean(false);
		}

		PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, prj1);

		return new BBoolean(range.contains(prj2));
	}

	public BBoolean notElementOf(BTuple<S,T> object) {
		S prj1 = object.projection1();
		T prj2 = object.projection2();

		PersistentHashSet domain = (PersistentHashSet) SET.invoke(KEYS.invoke(this.map));

		if(!domain.contains(prj1)) {
			return new BBoolean(true);
		}

		PersistentHashSet range = (PersistentHashSet) GET.invoke(this.map, prj1);

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
			if(range.size() == 0) {
				resultSet = DIFFERENCE.invoke(resultSet, SET.invoke(SEQ.invoke(LIST.invoke(domainElement))));
			}
		}
		return new BSet<S>(resultSet);
	}

	@SuppressWarnings("unchecked")
	public BSet<T> range() {
		PersistentHashSet set = (PersistentHashSet) REDUCE.invoke(UNION, SET.invoke(SEQ.invoke(LIST.invoke())), VALS.invoke(this.map));
		return new BSet<T>(set);
	}

	@SuppressWarnings("unchecked")
	public BRelation<T,S> inverse() {
		PersistentHashMap thisMap = this.map;
		PersistentHashSet keys = (PersistentHashSet) SET.invoke(KEYS.invoke(thisMap));

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(Object e1 : keys) {
			S domainElement = (S) e1;
			PersistentHashSet range = (PersistentHashSet) GET.invoke(thisMap, domainElement);
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
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, INTERSECTION.invoke(thisRangeSet, otherSet));
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
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, DIFFERENCE.invoke(thisRangeSet, otherSet));
		}
		return new BRelation<S, T>(resultMap);
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
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, i, SET.invoke(SEQ.invoke(LIST.invoke())));
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
	public <R,A> BRelation<R,A> conc() {
		BRelation<R,A> result = new BRelation<R,A>();
		BInteger size = this.card();
		for(BInteger i = new BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
			result = result.concat((BRelation<R,A>) functionCall((S) i));
		}
		return result;
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
			for(Object e2: range) {
				T rangeElement = (T) e2;
				set = (PersistentHashSet) UNION.invoke(set, (PersistentHashSet) GET.invoke(otherMap, rangeElement));
			}
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, set);
		}
		return new BRelation<S, R>(resultMap);
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> iterate(BInteger n) {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = identity(this.domain());
		for(BInteger i = new BInteger("1"); i.lessEqual(n).booleanValue(); i = i.succ()) {
			result = result.union(result.composition(thisRelation));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> closure() {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = identity(this.domain());
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
	public <R> BRelation<S,R> rel() {
		BSet<S> domain = this.domain();

		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(S domainElement : domain) {
			BSet<R> range = (BSet<R>) this.functionCall(domainElement);
			PersistentHashSet rangeSet = range.getSet();
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, domainElement, rangeSet);
		}
		return new BRelation<S, R>(resultMap);
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
	public static <S,T> BRelation<S,T> cartesianProduct(BSet<S> arg1, BSet<T> arg2) {
		PersistentHashMap resultMap = PersistentHashMap.EMPTY;
		for(S e1 : arg1) {
			resultMap = (PersistentHashMap) ASSOC.invoke(resultMap, e1, arg2.getSet());
		}
		return new BRelation<S, T>(resultMap);
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
		return this.domain().strictSubset(domain);
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
