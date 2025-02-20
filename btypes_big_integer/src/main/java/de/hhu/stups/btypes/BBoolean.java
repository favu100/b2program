package de.hhu.stups.btypes;

import java.util.Objects;

public final class BBoolean implements BObject {

	public static final BBoolean TRUE = new BBoolean(true);
	public static final BBoolean FALSE = new BBoolean(false);

	private final boolean value;

	public static BBoolean of(boolean value) {
		if (value) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	public static BBoolean of(String value) {
		return of(Boolean.parseBoolean(value));
	}

	public static BBoolean of(BBoolean value) {
		return Objects.requireNonNull(value, "value");
	}

	/**
	 * Please use BBoolean.of(...) instead.
	 */
	@Deprecated
	public BBoolean(boolean value) {
		this.value = value;
	}

	public BBoolean(String s) {
		this(Boolean.parseBoolean(s));
	}

	public boolean booleanValue() {
		return this.value;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) {
			return true;
		} else if (!(o instanceof BBoolean)) {
			return false;
		} else {
			return this.value == ((BBoolean) o).value;
		}
	}

	@Override
	public int hashCode() {
		return Boolean.hashCode(this.value);
	}

	@Override
	public String toString() {
		return String.valueOf(this.value);
	}

	public BBoolean or(BBoolean other) {
		return of(this.booleanValue() || other.booleanValue());
	}

	public BBoolean xor(BBoolean other) {
		return of(this.booleanValue() ^ other.booleanValue());
	}

	public BBoolean and(BBoolean other) {
		return of(this.booleanValue() && other.booleanValue());
	}

	public BBoolean not() {
		return of(!this.booleanValue());
	}

	public BBoolean implies(BBoolean other) {
		return this.not().or(other);
	}

	public BBoolean equivalent(BBoolean other) {
		return of(this.booleanValue() == other.booleanValue());
	}

	public BBoolean equal(BBoolean other) {
		return of(this.booleanValue() == other.booleanValue());
	}

	public BBoolean unequal(BBoolean other) {
		return of(this.booleanValue() != other.booleanValue());
	}

	public BBoolean isBoolean() {
		return TRUE;
	}

	public BBoolean isNotBoolean() {
		return FALSE;
	}
}
