package de.hhu.stups.btypes;

import clojure.java.api.Clojure;
import clojure.lang.AFn;
import clojure.lang.IFn;
import clojure.lang.PersistentHashSet;
import clojure.lang.RT;
import clojure.lang.Var;

import java.util.Collection;
import java.util.Iterator;
import java.util.Set;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Optional;

import java.lang.reflect.GenericDeclaration;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.lang.reflect.Method;

import java.util.Objects;

public class BSet<T> implements Set<T>, BObject {

	private static final class createBInteger extends AFn {
		@Override
		public Object invoke(Object obj) {
			return new BInteger(Integer.parseInt(obj.toString()));
		}
	}

	protected static final Var SET;

	protected static final Var EMPTY;

	protected static final Var COUNT;

	protected static final IFn INTERSECTION;

	protected static final IFn UNION;

	protected static final IFn DIFFERENCE;

	protected static final IFn RANGE;

	protected static final IFn MAP;

	protected static final IFn INC;

	protected static final IFn CREATE_INTEGER;


	static {
		RT.var("clojure.core", "require").invoke(Clojure.read("clojure.set"));
		SET = RT.var("clojure.core", "set");
		EMPTY = RT.var("clojure.core", "empty?");
		COUNT = RT.var("clojure.core", "count");
		INTERSECTION = RT.var("clojure.set", "intersection");
		UNION = RT.var("clojure.set", "union");
		DIFFERENCE = RT.var("clojure.set", "difference");
		RANGE = RT.var("clojure.core", "range");
		MAP = RT.var("clojure.core", "map");
		INC = RT.var("clojure.core", "inc");
		CREATE_INTEGER = new createBInteger();
	}

	protected final PersistentHashSet set;

	public BSet(PersistentHashSet elements) {
		this.set = elements;
	}

	@SuppressWarnings("unchecked")
	@SafeVarargs
	public BSet(T... elements) {
		this.set = (PersistentHashSet) SET.invoke(elements);
	}

	public java.lang.String toString() {
		Iterator<T> it = this.iterator();
		StringBuffer sb = new StringBuffer();
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

	@SuppressWarnings("unchecked")
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		BSet<T> bObjects = (BSet<T>) o;

		return set.equals(bObjects.set);
	}

	public int hashCode() {
		return set.hashCode();
	}

	public boolean removeAll(Collection<?> c) {
		throw new UnsupportedOperationException();
	}

	@SuppressWarnings("unchecked")
	public T[] toArray() {
		return (T[]) set.toArray();
	}

	@SuppressWarnings("unchecked")
	public <T> T[] toArray(T[] a) {
		return (T[]) set.toArray(a);
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
		return new BSet<T>((PersistentHashSet) INTERSECTION.invoke(this.set, set.set));
	}

	@SuppressWarnings("unchecked")
	public <K extends BObject> T intersect() {
		if (set.isEmpty()) {
			//Think about passing the generic inner class through the constructor (or at least with a method)
			try {
				return (T) new BSet<K>();
			} catch (ClassCastException e) {
				return (T) new BRelation();
			}
		} else {
			//Think about passing the generic inner class through the constructor (or at least with a method)
			try {
				return (T) this.set.stream()
						.reduce((a, e) -> ((BSet<K>) a).intersect((BSet<K>) e)).get();
			} catch (ClassCastException exception) {
				return (T) this.set.stream()
						.reduce((a, e) -> ((BRelation) a).intersect((BRelation) e)).get();
			}
		}
	}

	public BSet<T> difference(BSet<T> set) {
		return new BSet<T>((PersistentHashSet) DIFFERENCE.invoke(this.set, set.set));
	}

	public BSet<T> union(BSet<T> set) {
		return new BSet<T>((PersistentHashSet) UNION.invoke(this.set, set.set));
	}

	@SuppressWarnings("unchecked")
	public <K extends BObject> BSet<K> unionForSets() {
		if(set.isEmpty()) {
			return new BSet<K>();
		} else {
			return (BSet<K>) this.set.stream()
					.reduce(new BSet<K>(), (a, e) -> ((BSet<K>) a).union((BSet<K>) e));
		}
	}

	@SuppressWarnings("unchecked")
	public <T1 extends BObject, T2 extends BObject> BRelation<T1, T2> unionForRelations() {
		if(set.isEmpty()) {
			return new BRelation<T1,T2>();
		} else {
			return (BRelation<T1,T2>) this.set.stream()
					.reduce(new BRelation<T1, T2>(), (a, e) -> ((BRelation<T1, T2>) a).union((BRelation<T1, T2>) e));
		}
	}

	public static BSet<BInteger> interval(BInteger a, BInteger b) {
		PersistentHashSet persistentSet = PersistentHashSet.create();
		for(BInteger i = a; i.lessEqual(b).booleanValue(); i = i.plus(new BInteger(1))) {
			persistentSet = (PersistentHashSet) persistentSet.cons(i);
		}
		return new BSet<BInteger>(persistentSet);
	}


	public BInteger card() {
		return new BInteger((int) COUNT.invoke(this.set));
	}

	public BInteger _size() {
		return new BInteger((int) COUNT.invoke(this.set));
	}

	public BBoolean elementOf(T object) {
		return new BBoolean(this.set.contains(object));
	}

	public BBoolean notElementOf(T object) {
		return new BBoolean(!this.set.contains(object));
	}

	public BBoolean equal(BSet<T> o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BSet<T> o) {
		return new BBoolean(!equals(o));
	}

	public BBoolean subset(BSet<T> set) {
		return new BBoolean(set.containsAll(this));
	}

	public BBoolean notSubset(BSet<T> set) {
		return new BBoolean(!set.containsAll(this));
	}

	public BBoolean strictSubset(BSet<T> set) {
		return new BBoolean(set.size() != this.set.size() && set.containsAll(this));
	}

	public BBoolean strictNotSubset(BSet<T> set) {
		return new BBoolean(set.size() == this.set.size() || !set.containsAll(this));
	}

	public T nondeterminism() {
		int index = (int) Math.floor(Math.random() * set.size());
		return nondeterminism(index);
	}

	public T nondeterminism(int index) {
		if(index >= this.size()) {
			return null;
		}
		return toArray()[index];
	}

	@SuppressWarnings("unchecked")
	public BInteger min() {
		Optional<BInteger> result = this.set.stream().reduce((a,b) -> ((BInteger) a).lessEqual((BInteger) b).booleanValue() ? (BInteger) a : (BInteger) b);
		if(result.isPresent()) {
			return result.get();
		}
		throw new RuntimeException("Minumum does not exist");
	}

	@SuppressWarnings("unchecked")
	public BInteger max() {
		Optional<BInteger> result = this.set.stream().reduce((a,b) -> ((BInteger) a).greaterEqual((BInteger) b).booleanValue() ? (BInteger) a : (BInteger) b);
		if(result.isPresent()) {
			return result.get();
		}
		throw new RuntimeException("Maximum does not exist");
	}

	@SuppressWarnings("unchecked")
	public <K extends BSet<T>> BSet<K> pow() {
		BSet<K> result = new BSet<K>();
		K start = (K) new BSet<T>();
		Queue<K> queue = new LinkedList<>();
		queue.add(start);
		result = result.union(new BSet<K>(start));
		while(!queue.isEmpty()) {
			K currentSet = queue.remove();
			for(T element : this) {
				K nextSet = (K) currentSet.union(new BSet<T>(element));
				int previousSize = result.size();
				result = result.union(new BSet<K>(nextSet));
				if(previousSize < result.size()) {
					queue.add(nextSet);
				}
			}
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public <K extends BSet<T>> BSet<K> pow1() {
		BSet<T> emptySet = new BSet<T>();
		return this.pow().difference(new BSet(emptySet));
	}

	public <K extends BSet<T>> BSet<K> fin() {
		return this.pow();
	}

	public <K extends BSet<T>> BSet<K> fin1() {
		return this.pow1();
	}

	public BSet<BRelation<BInteger,T>> permutate() {
		BSet<BInteger> interval = BSet.interval(new BInteger(1), this._size());
		BSet<BRelation<BInteger,T>> permutations = BRelation.cartesianProduct(interval, this).pow();
		BSet<BRelation<BInteger,T>> result = permutations;
		for(BRelation<BInteger, T> permutation : permutations) {
			if(!permutation.isBijection(this).booleanValue()) {
				result = result.difference(new BSet<BRelation<BInteger, T>>(permutation));
			}
		}
		return result;
	}

	public BBoolean subsetOfInteger() {
		for(T e : this) {
			if(e instanceof BInteger) {
				return new BBoolean(true);
			} else {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
	}

	public BBoolean strictSubsetOfInteger() {
		return subsetOfInteger();
	}

	public BBoolean notSubsetOfInteger() {
		return subsetOfInteger().not();
	}

	public BBoolean equalInteger() {
		return new BBoolean(false);
	}

	public BBoolean unequalInteger() {
		return new BBoolean(true);
	}

	public BBoolean equalNatural() {
		return new BBoolean(false);
	}

	public BBoolean unequalNatural() {
		return new BBoolean(true);
	}

	public BBoolean equalNatural1() {
		return new BBoolean(false);
	}

	public BBoolean unequalNatural1() {
		return new BBoolean(true);
	}

	public BBoolean equalString() {
		return new BBoolean(false);
	}

	public BBoolean unequalString() {
		return new BBoolean(true);
	}

	public BBoolean equalStruct() {
		return new BBoolean(false);
	}

	public BBoolean unequalStruct() {
		return new BBoolean(true);
	}

	public BBoolean notStrictSubsetOfInteger() {
		return strictSubsetOfInteger().not();
	}

	public BBoolean subsetOfNatural() {
		for(T e : this) {
			BInteger element = (BInteger) e;
			if(!element.isNatural().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
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
		for(T e : this) {
			BInteger element = (BInteger) e;
			if(!element.isNatural1().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
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
		for(T e : this) {
			BString element = (BString) e;
			if(!element.isString().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
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
		for(T e : this) {
			BStruct element = (BStruct) e;
			if(!element.isRecord().booleanValue()) {
				return new BBoolean(false);
			}
		}
		return new BBoolean(true);
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