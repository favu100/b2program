package de.hhu.stups.btypes;

import com.google.common.collect.ImmutableSet;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.stream.Collectors;

public class BSet<T> implements BObject, Set<T> {

	protected final ImmutableSet<T> set;

	public BSet(java.util.Set<T> elements) {
		this.set = ImmutableSet.copyOf(elements);
	}

	public BSet(T... elements) {
		this.set = ImmutableSet.copyOf(elements);
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
		return new BSet<>(this.stream()
				.filter(set::contains)
				.collect(Collectors.toSet()));
	}

	public BSet<T> difference(BSet<T> set) {
		return new BSet<>(this.stream()
				.filter(element -> !set.contains(element))
				.collect(Collectors.toSet()));
	}

	public BSet<T> union(BSet<T> set) {
		HashSet<T> result = new HashSet<>(this);
		result.addAll(set);
		return new BSet<>(result);
	}

	public static BSet<BInteger> range(BInteger a, BInteger b) {
		HashSet<BInteger> set = new HashSet<>();
		for (BInteger i = a; i.lessEqual(b).booleanValue(); i = (BInteger) i.next()) {
			set.add(i);
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

}
