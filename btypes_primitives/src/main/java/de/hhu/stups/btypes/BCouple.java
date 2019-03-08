package de.hhu.stups.btypes;

import java.util.Objects;

public class BCouple<S,T> implements BObject {

	private S first;

	private T second;

	public BCouple(S first, T second) {
		if (first == null || second == null) {
			throw new IllegalArgumentException();
		}
		this.first = first;
		this.second = second;
	}


	public boolean equals(Object o) {
		if (this == o) {
			return true;
		}
		if (o == null || getClass() != o.getClass()) {
			return false;
		}

        BCouple bObjects = (BCouple) o;
		// elements is never null
		return bObjects.projection1().equals(this.first) && bObjects.projection2().equals(this.second);
	}

	public int hashCode() {
		return Objects.hash(first, second);
	}

	@Override
	public java.lang.String toString() {
		return "(" + this.projection1() + " |-> " + this.projection2() + ')';
	}

	public S projection1() {
		return first;
	}

	public T projection2() {
		return second;
	}

	public BBoolean equal(BCouple o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BCouple o) {
		return new BBoolean(!equals(o));
	}

}
