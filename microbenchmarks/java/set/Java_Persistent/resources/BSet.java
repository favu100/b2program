package de.hhu.stups.btypes;

import org.pcollections.HashTreePSet;
import org.pcollections.PSet;

import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

public class BSet<T> implements BObject, Set<T> {

	protected final PSet<T> set;

	public BSet(PSet<T> elements) {
		this.set = elements;
	}

	public BSet(T... elements) {
		this.set = HashTreePSet.from(Arrays.asList(elements));
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
		return this.set.size();
	}

	public boolean isEmpty() {
		return this.set.isEmpty();
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
		return set.toArray(a);
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
		if(this.size() < set.size()) {
			return new BSet<>(this.set.minusAll(this.set.minusAll(set)));
		} else {
			return new BSet<>(set.set.minusAll(set.set.minusAll(this)));
		}
	}

	public BSet<T> difference(BSet<T> set) {
		return new BSet<>(this.set.minusAll(set));
	}

	public BSet<T> union(BSet<T> set) {
		return new BSet<>(this.set.plusAll(set));
	}

	public static BSet<BInteger> range(BInteger a, BInteger b) {
		PSet<BInteger> set = HashTreePSet.empty();
		for(BInteger i = a; i.lessEqual(b).booleanValue(); i = (BInteger) i.next()) {
			set = set.plus(i);
		}
		return new BSet<>(set);
	}

	public BInteger card() {
		return new BInteger(this.size());
	}

	public BBoolean elementOf(T object) {
		return new BBoolean(this.contains(object));
	}

	public BBoolean equal(BSet<T> o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BSet<T> o) {
		return new BBoolean(!equals(o));
	}

	public T nondeterminism() {
		int index = (int) Math.floor(Math.random() * set.size());
		return toArray()[index];
	}

}