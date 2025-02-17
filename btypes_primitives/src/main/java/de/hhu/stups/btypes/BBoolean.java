package de.hhu.stups.btypes;

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

	/* groovy operator overloading support */
	Object asType(Class<?> clazz) {
		if (clazz == BBoolean.class) {
			return this;
		}
		return clazz.cast(this.value);
	}

	public BBoolean or(BBoolean other) {
		return new BBoolean(this.booleanValue() || other.booleanValue());
	}

	public BBoolean or(boolean other) {
		return new BBoolean(this.booleanValue() || other);
	}

	public BBoolean xor(BBoolean other) {
		return new BBoolean(this.booleanValue() ^ other.booleanValue());
	}

	public BBoolean xor(boolean other) {
		return new BBoolean(this.booleanValue() ^ other);
	}

	public BBoolean and(BBoolean other) {
		return new BBoolean(this.booleanValue() && other.booleanValue());
	}

	public BBoolean and(boolean other) {
		return new BBoolean(this.booleanValue() && other);
	}

	public BBoolean not() {
		return new BBoolean(!this.booleanValue());
	}

	public BBoolean implies(BBoolean other) {
		return this.not().or(other);
	}

	public BBoolean implies(boolean other) {
		return new BBoolean(this.not().booleanValue() || other);
	}

	public BBoolean equivalent(BBoolean other) {
		return new BBoolean(this.booleanValue() == other.booleanValue());
	}

	public BBoolean equivalent(boolean other) {
		return new BBoolean(this.booleanValue() == other);
	}

	public BBoolean equal(BBoolean other) {
		return new BBoolean(this.booleanValue() == other.booleanValue());
	}

	public BBoolean unequal(BBoolean other) {
		return new BBoolean(this.booleanValue() != other.booleanValue());
	}

	public BBoolean isBoolean() {
		return TRUE;
	}

	public BBoolean isNotBoolean() {
		return FALSE;
	}
}
