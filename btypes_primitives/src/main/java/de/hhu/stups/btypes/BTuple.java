package de.hhu.stups.btypes;

import java.util.Objects;

public final class BTuple<S, T> implements BObject {

	private final S first;
	private final T second;

	public BTuple(S first, T second) {
		this.first = Objects.requireNonNull(first, "first");
		this.second = Objects.requireNonNull(second, "second");
	}

	public boolean equals(Object o) {
		if (this == o) {
			return true;
		} else if (!(o instanceof BTuple)) {
			return false;
		} else {
			BTuple<?, ?> that = (BTuple<?, ?>) o;
			return this.first.equals(that.first) && this.second.equals(that.second);
		}
	}

	public int hashCode() {
		return Objects.hash(this.first, this.second);
	}

	@Override
	public String toString() {
		return "(" + this.first + " |-> " + this.second + ")";
	}

	public S projection1() {
		return this.first;
	}

	public T projection2() {
		return this.second;
	}

	public BBoolean equal(BTuple<?, ?> o) {
		return BBoolean.of(this.equals(o));
	}

	public BBoolean unequal(BTuple<?, ?> o) {
		return BBoolean.of(!this.equals(o));
	}
}
