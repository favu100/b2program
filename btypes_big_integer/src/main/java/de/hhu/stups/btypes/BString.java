package de.hhu.stups.btypes;

import java.util.Objects;

public final class BString implements BObject {

	private final String value;

	public BString(String value) {
		this.value = Objects.requireNonNull(value, "value");
	}

	public String getValue() {
		return this.value;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) {
			return true;
		} else if (!(o instanceof BString)) {
			return false;
		} else {
			return this.value.equals(((BString) o).value);
		}
	}

	@Override
	public int hashCode() {
		return this.value.hashCode();
	}

	@Override
	public String toString() {
		return '"' + this.value + '"';
	}

	public BBoolean isString() {
		return BBoolean.TRUE;
	}

	public BBoolean isNotString() {
		return BBoolean.FALSE;
	}

	public BBoolean equal(BString o) {
		return BBoolean.of(this.equals(o));
	}

	public BBoolean unequal(BString o) {
		return BBoolean.of(!this.equals(o));
	}
}
