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

public class BSet<T> implements BObject, Set<T> {

	private static final class createBInteger extends AFn {
		@Override
		public Object invoke(Object obj) {
			return new BInteger(Integer.parseInt(obj.toString()));
		}
	}

	private static final Var SET;

	private static final Var EMPTY;

	private static final Var COUNT;

	private static final IFn INTERSECTION;

	private static final IFn UNION;

	private static final IFn DIFFERENCE;

	private static final IFn RANGE;

	private static final IFn MAP;

	private static final IFn INC;

	private static final IFn CREATE_INTEGER;


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

	public BSet(Object... elements) {
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

	public Object[] toArray() {
		return set.toArray();
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

	public BSet<T> difference(BSet<T> set) {
		return new BSet<>((PersistentHashSet) DIFFERENCE.invoke(this.set, set.set));
	}

	public BSet<T> union(BSet<T> set) {
		return new BSet<>((PersistentHashSet) UNION.invoke(this.set, set.set));
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

	public BBoolean equal(BSet<T> o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BSet<T> o) {
		return new BBoolean(!equals(o));
	}

	public T nondeterminism() {
		int index = (int) Math.floor(Math.random() * set.size());
		return (T) toArray()[index];
	}
}