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

public class BSet<T> implements BObject, Set<T> {

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

	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		BSet bObjects = (BSet) o;

		if (!set.equals(bObjects.set))
			return false;

		return true;
	}

	public int hashCode() {
		return set.hashCode();
	}

	public boolean removeAll(Collection<?> c) {
		throw new UnsupportedOperationException();
	}

	public T[] toArray() {
		return (T[]) set.toArray();
	}

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

	public Iterator<T> iterator() {
		return set.iterator();
	}

	public BSet<T> intersect(BSet<T> set) {
		return new BSet<>((PersistentHashSet) INTERSECTION.invoke(this.set, set.set));
	}

	public <K extends BObject> T intersect() {
		if (set.isEmpty()) {
			return (T) new BSet<K>();
		} else {
			return (T) this.set.stream()
					.reduce((a,e) -> ((BSet<K>) a).intersect((BSet<K>) e)).get();
		}

	}

	public BSet<T> difference(BSet<T> set) {
		return new BSet<>((PersistentHashSet) DIFFERENCE.invoke(this.set, set.set));
	}

	public BSet<T> union(BSet<T> set) {
		return new BSet<>((PersistentHashSet) UNION.invoke(this.set, set.set));
	}

	public <K extends BObject> T union() {
		if (set.isEmpty()) {
			return (T) new BSet<K>();
		} else {
			return (T) this.set.stream()
					.reduce((a,e) -> ((BSet<K>) a).union((BSet<K>) e)).get();
		}

	}

	public static BSet<BInteger> range(BInteger a, BInteger b) {
		return new BSet<>((PersistentHashSet) SET.invoke(
				MAP.invoke(CREATE_INTEGER, RANGE.invoke(a.getValue(), INC.invoke(b.getValue())))));
	}


	public BInteger card() {
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
		return toArray()[index];
	}

	public BInteger min() {
		Optional<BInteger> result = this.set.stream().reduce((a,b) -> ((BInteger) a).lessEqual((BInteger) b).booleanValue() ? (BInteger) a : (BInteger) b);
		if(result.isPresent()) {
			return result.get();
		}
		throw new RuntimeException("Minumum does not exist");
	}

	public BInteger max() {
		Optional<BInteger> result = this.set.stream().reduce((a,b) -> ((BInteger) a).greaterEqual((BInteger) b).booleanValue() ? (BInteger) a : (BInteger) b);
		if(result.isPresent()) {
			return result.get();
		}
		throw new RuntimeException("Maximum does not exist");
	}

	public BSet<BSet<T>> pow() {
		BSet<BSet<T>> result = new BSet<>();
		BSet<T> start = new BSet<>();
		Queue<BSet<T>> queue = new LinkedList<>();
		queue.add(start);
		while(!queue.isEmpty()) {
			BSet<T> currentSet = queue.remove();
			for(T element : this) {
				BSet<T> nextSet = currentSet.union(new BSet<>(element));
				int previousSize = result.size();
				result = result.union(new BSet<>(nextSet));
				if(previousSize < result.size()) {
					queue.add(nextSet);
				}
			}
		}
		return result;
	}

	public BSet<BSet<T>> fin() {
		return this.pow();
	}

	public BRelation<T,T> identity() {
		BRelation<T,T> result = new BRelation<>();
		for(T e : this) {
			result = result.union(new BRelation<>(new BCouple<>(e,e)));
		}
		return result;
	}

	public <S> BRelation<T,S> cartesianProduct(BSet<S> set) {
		BRelation<T,S> result = new BRelation<>();
		for(T e1 : this) {
			for(S e2 : set) {
				result = result.union(new BRelation<>(new BCouple(e1,e2)));
			}
		}
		return result;
	}
}