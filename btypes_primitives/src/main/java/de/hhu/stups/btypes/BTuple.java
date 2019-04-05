package de.hhu.stups.btypes;

import java.util.Objects;

public class BTuple<S,T> implements BObject {

	private S first;

	private T second;

	public BTuple(S first, T second) {
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

        BTuple bObjects = (BTuple) o;
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

	public BBoolean equal(BTuple o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BTuple o) {
		return new BBoolean(!equals(o));
	}

}
