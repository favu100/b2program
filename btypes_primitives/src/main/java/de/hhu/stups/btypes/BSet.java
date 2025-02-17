package de.hhu.stups.btypes;

import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Objects;
import java.util.Optional;
import java.util.Queue;
import java.util.Set;

import clojure.java.api.Clojure;
import clojure.lang.IFn;
import clojure.lang.PersistentHashSet;
import clojure.lang.RT;
import clojure.lang.Var;

public final class BSet<T> implements BObject, Set<T> {

	private static final Var SET;
	private static final Var EMPTY;
	private static final Var COUNT;
	private static final IFn INTERSECTION;
	private static final IFn UNION;
	private static final IFn DIFFERENCE;

	static {
		RT.var("clojure.core", "require").invoke(Clojure.read("clojure.set"));
		SET = RT.var("clojure.core", "set");
		EMPTY = RT.var("clojure.core", "empty?");
		COUNT = RT.var("clojure.core", "count");
		INTERSECTION = RT.var("clojure.set", "intersection");
		UNION = RT.var("clojure.set", "union");
		DIFFERENCE = RT.var("clojure.set", "difference");
	}

	private final PersistentHashSet set;

	BSet(PersistentHashSet elements) {
		this.set = Objects.requireNonNull(elements, "elements");
	}

	@SafeVarargs
	public BSet(T... elements) {
		this.set = (PersistentHashSet) SET.invoke(elements);
	}

	public String toString() {
		Iterator<T> it = this.iterator();
		StringBuilder sb = new StringBuilder();
		sb.append("{");
		while (it.hasNext()) {
			T b = it.next();
			sb.append(b.toString());
			if (it.hasNext()) {
				sb.append(", ");
			}
		}
		sb.append("}");
		return sb.toString();
	}

	public int size() {
		return (int) COUNT.invoke(this.set);
	}

	public boolean isEmpty() {
		return (boolean) EMPTY.invoke(this.set);
	}

	public boolean contains(Object o) {
		return set.contains(o);
	}

	public boolean add(T bObject) {
		throw new UnsupportedOperationException();
	}

	public boolean remove(Object o) {
		throw new UnsupportedOperationException();
	}

	public void clear() {
		throw new UnsupportedOperationException();
	}

	public boolean equals(Object o) {
		if (this == o) {
			return true;
		} else if (!(o instanceof BSet)) {
			return false;
		} else {
			return this.set.equals(((BSet<?>) o).set);
		}
	}

	public int hashCode() {
		return this.set.hashCode();
	}

	public boolean removeAll(Collection<?> c) {
		throw new UnsupportedOperationException();
	}

	public Object[] toArray() {
		return set.toArray();
	}

	@SuppressWarnings("unchecked")
	public <A> A[] toArray(A[] a) {
		return (A[]) set.toArray(a);
	}

	public boolean containsAll(Collection<?> c) {
		return set.containsAll(c);
	}

	public boolean addAll(Collection<? extends T> c) {
		throw new UnsupportedOperationException();
	}

	public boolean retainAll(Collection<?> c) {
		throw new UnsupportedOperationException();
	}

	@SuppressWarnings("unchecked")
	public Iterator<T> iterator() {
		return set.iterator();
	}

	public BSet<T> intersect(BSet<T> set) {
		return new BSet<>((PersistentHashSet) INTERSECTION.invoke(this.set, set.set));
	}

	public BSet<T> difference(BSet<T> set) {
		return new BSet<>((PersistentHashSet) DIFFERENCE.invoke(this.set, set.set));
	}

	public BSet<T> union(BSet<T> set) {
		return new BSet<>((PersistentHashSet) UNION.invoke(this.set, set.set));
	}

	@SuppressWarnings("unchecked")
	public <K extends BObject> T unionForSets() {
		if (set.isEmpty()) {
			return (T) new BSet<K>();
		} else {
			return (T) this.set.stream()
					           .reduce(new BSet<K>(), (a, e) -> ((BSet<K>) a).union((BSet<K>) e));
		}
	}

	@SuppressWarnings("unchecked")
	public <T1 extends BObject, T2 extends BObject> T unionForRelations() {
		if (set.isEmpty()) {
			return (T) new BRelation<T1, T2>();
		} else {
			return (T) this.set.stream()
					           .reduce(new BRelation<T1, T2>(), (a, e) -> ((BRelation<T1, T2>) a).union((BRelation<T1, T2>) e));
		}
	}


	@SuppressWarnings("unchecked")
	public <K extends BObject> T intersectForSets() {
		if (set.isEmpty()) {
			return (T) new BSet<K>();
		} else {
			return (T) this.set.stream()
					           .reduce((a, e) -> ((BSet<K>) a).intersect((BSet<K>) e)).get();
		}
	}

	@SuppressWarnings("unchecked")
	public <T1 extends BObject, T2 extends BObject> T intersectForRelations() {
		if (set.isEmpty()) {
			return (T) new BRelation<T1, T2>();
		} else {
			return (T) this.set.stream()
					           .reduce((a, e) -> ((BRelation<T1, T2>) a).intersect((BRelation<T1, T2>) e)).get();
		}
	}

	public static BSet<BInteger> interval(BInteger a, BInteger b) {
		PersistentHashSet persistentSet = PersistentHashSet.create();
		for (BInteger i = a; i.lessEqual(b).booleanValue(); i = i.succ()) {
			persistentSet = (PersistentHashSet) persistentSet.cons(i);
		}
		return new BSet<>(persistentSet);
	}

	public BInteger card() {
		return BInteger.of((int) COUNT.invoke(this.set));
	}

	public BInteger _size() {
		return BInteger.of((int) COUNT.invoke(this.set));
	}

	public BBoolean elementOf(T object) {
		return BBoolean.of(this.set.contains(object));
	}

	public BBoolean notElementOf(T object) {
		return BBoolean.of(!this.set.contains(object));
	}

	public BBoolean equal(BSet<T> o) {
		return BBoolean.of(equals(o));
	}

	public BBoolean unequal(BSet<T> o) {
		return BBoolean.of(!equals(o));
	}

	public BBoolean subset(BSet<T> set) {
		return BBoolean.of(set.containsAll(this));
	}

	public BBoolean notSubset(BSet<T> set) {
		return BBoolean.of(!set.containsAll(this));
	}

	public BBoolean strictSubset(BSet<T> set) {
		return BBoolean.of(set.size() != this.set.size() && set.containsAll(this));
	}

	public BBoolean strictNotSubset(BSet<T> set) {
		return BBoolean.of(set.size() == this.set.size() || !set.containsAll(this));
	}

	public T nondeterminism() {
		int index = (int) Math.floor(Math.random() * set.size());
		return nondeterminism(index);
	}

	@SuppressWarnings("unchecked")
	public T nondeterminism(int index) {
		if (index >= this.size()) {
			return null;
		}
		return (T) toArray()[index];
	}

	@SuppressWarnings("unchecked")
	public BInteger min() {
		if (this.set.isEmpty()) {
			throw new RuntimeException("Minimum does not exist");
		}
		return (BInteger) Collections.min(this.set);
	}

	@SuppressWarnings("unchecked")
	public BInteger max() {
		if (this.set.isEmpty()) {
			throw new RuntimeException("Maximum does not exist");
		}
		return (BInteger) Collections.max(this.set);
	}

	@SuppressWarnings("unchecked")
	public <K extends BSet<T>> BSet<K> pow() {
		BSet<K> result = new BSet<K>();
		K start = (K) new BSet<T>();
		Queue<K> queue = new LinkedList<>();
		queue.add(start);
		result = result.union(new BSet<K>(start));
		while (!queue.isEmpty()) {
			K currentSet = queue.remove();
			for (T element : this) {
				K nextSet = (K) currentSet.union(new BSet<T>(element));
				int previousSize = result.size();
				result = result.union(new BSet<>(nextSet));
				if (previousSize < result.size()) {
					queue.add(nextSet);
				}
			}
		}
		return result;
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	public <K extends BSet<T>> BSet<K> pow1() {
		BSet<T> emptySet = new BSet<>();
		return this.pow().difference(new BSet(emptySet));
	}

	public <K extends BSet<T>> BSet<K> fin() {
		return this.pow();
	}

	public <K extends BSet<T>> BSet<K> fin1() {
		return this.pow1();
	}

	public BSet<BRelation<BInteger, T>> permutate() {
		BSet<BInteger> interval = BSet.interval(BInteger.ONE, this._size());
		BSet<BRelation<BInteger, T>> permutations = BRelation.cartesianProduct(interval, this).pow();
		BSet<BRelation<BInteger, T>> result = permutations;
		for (BRelation<BInteger, T> permutation : permutations) {
			if (!permutation.isBijection(this).booleanValue()) {
				result = result.difference(new BSet<>(permutation));
			}
		}
		return result;
	}

	public BBoolean subsetOfBoolean() {
		for (T e : this) {
			if (e instanceof BBoolean) {
				return BBoolean.TRUE;
			} else {
				return BBoolean.FALSE;
			}
		}
		return BBoolean.TRUE;
	}

	public BBoolean strictSubsetOfBoolean() {
		return BBoolean.of(subsetOfBoolean().booleanValue() && this.size() < 2);
	}

	public BBoolean notSubsetOfBoolean() {
		return subsetOfBoolean().not();
	}

	public BBoolean equalBoolean() {
		return BBoolean.of(subsetOfBoolean().booleanValue() && this.size() == 2);
	}

	public BBoolean unequalBoolean() {
		return BBoolean.of(subsetOfBoolean().booleanValue() && this.size() < 2);
	}

	public BBoolean subsetOfInteger() {
		for (T e : this) {
			if (e instanceof BInteger) {
				return BBoolean.TRUE;
			} else {
				return BBoolean.FALSE;
			}
		}
		return BBoolean.TRUE;
	}

	public BBoolean strictSubsetOfInteger() {
		return subsetOfInteger();
	}

	public BBoolean notSubsetOfInteger() {
		return subsetOfInteger().not();
	}

	public BBoolean equalInteger() {
		return BBoolean.FALSE;
	}

	public BBoolean unequalInteger() {
		return BBoolean.TRUE;
	}

	public BBoolean equalNatural() {
		return BBoolean.FALSE;
	}

	public BBoolean unequalNatural() {
		return BBoolean.TRUE;
	}

	public BBoolean equalNatural1() {
		return BBoolean.FALSE;
	}

	public BBoolean unequalNatural1() {
		return BBoolean.TRUE;
	}

	public BBoolean equalString() {
		return BBoolean.FALSE;
	}

	public BBoolean unequalString() {
		return BBoolean.TRUE;
	}

	public BBoolean equalStruct() {
		return BBoolean.FALSE;
	}

	public BBoolean unequalStruct() {
		return BBoolean.TRUE;
	}

	public BBoolean notStrictSubsetOfInteger() {
		return strictSubsetOfInteger().not();
	}

	public BBoolean subsetOfNatural() {
		for (T e : this) {
			BInteger element = (BInteger) e;
			if (!element.isNatural().booleanValue()) {
				return BBoolean.FALSE;
			}
		}
		return BBoolean.TRUE;
	}

	public BBoolean strictSubsetOfNatural() {
		return subsetOfNatural();
	}

	public BBoolean notSubsetOfNatural() {
		return subsetOfNatural().not();
	}

	public BBoolean notStrictSubsetOfNatural() {
		return strictSubsetOfNatural().not();
	}

	public BBoolean subsetOfNatural1() {
		for (T e : this) {
			BInteger element = (BInteger) e;
			if (!element.isNatural1().booleanValue()) {
				return BBoolean.FALSE;
			}
		}
		return BBoolean.TRUE;
	}

	public BBoolean strictSubsetOfNatural1() {
		return subsetOfNatural1();
	}

	public BBoolean notSubsetOfNatural1() {
		return subsetOfNatural1().not();
	}

	public BBoolean notStrictSubsetOfNatural1() {
		return strictSubsetOfNatural1().not();
	}

	public BBoolean subsetOfString() {
		for (T e : this) {
			BString element = (BString) e;
			if (!element.isString().booleanValue()) {
				return BBoolean.FALSE;
			}
		}
		return BBoolean.TRUE;
	}

	public BBoolean strictSubsetOfString() {
		return subsetOfString();
	}

	public BBoolean notSubsetOfString() {
		return subsetOfString().not();
	}

	public BBoolean notStrictSubsetOfString() {
		return strictSubsetOfString().not();
	}


	public BBoolean subsetOfStruct() {
		for (T e : this) {
			BStruct element = (BStruct) e;
			if (!element.isRecord().booleanValue()) {
				return BBoolean.FALSE;
			}
		}
		return BBoolean.TRUE;
	}

	public BBoolean strictSubsetOfStruct() {
		return subsetOfStruct();
	}

	public BBoolean notSubsetOfStruct() {
		return subsetOfStruct().not();
	}

	public BBoolean notStrictSubsetOfStruct() {
		return strictSubsetOfStruct().not();
	}

	public PersistentHashSet getSet() {
		return set;
	}
}
