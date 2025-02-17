package de.hhu.stups.btypes;

import java.math.BigInteger;
import java.util.Objects;

public final class BInteger extends Number implements Comparable<BInteger>, BObject {

	public static final BInteger ZERO = new BInteger(0);
	public static final BInteger ONE = new BInteger(1);
	public static final BInteger TWO = new BInteger(2);
	public static final BInteger MINUS_ONE = new BInteger(-1);

	public static BInteger of(int value) {
		switch (value) {
			case 0:
				return ZERO;
			case 1:
				return ONE;
			case 2:
				return TWO;
			case -1:
				return MINUS_ONE;
			default:
				return new BInteger(value);
		}
	}

	public static BInteger of(long value) {
		return of(Math.toIntExact(value));
	}

	public static BInteger of(BigInteger value) {
		return of(value.intValueExact());
	}

	public static BInteger of(String value) {
		return of(Integer.parseInt(value));
	}

	public static BInteger of(BInteger value) {
		return Objects.requireNonNull(value, "value");
	}

	private final int value;

	private BInteger(int value) {
		this.value = value;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) {
			return true;
		} else if (!(o instanceof BInteger)) {
			return false;
		} else {
			return this.value == ((BInteger) o).value;
		}
	}

	@Override
	public int hashCode() {
		return Integer.hashCode(value);
	}

	@Override
	public int compareTo(BInteger o) {
		return Integer.compare(this.value, o.value);
	}

	public BBoolean lessEqual(BInteger o) {
		return BBoolean.of(this.value <= o.value);
	}

	public BBoolean greaterEqual(BInteger o) {
		return BBoolean.of(this.value >= o.value);
	}

	public BBoolean less(BInteger o) {
		return BBoolean.of(this.value < o.value);
	}

	public BBoolean greater(BInteger o) {
		return BBoolean.of(this.value > o.value);
	}

	public BBoolean equal(BInteger o) {
		return BBoolean.of(this.value == o.value);
	}

	public BBoolean unequal(BInteger o) {
		return BBoolean.of(this.value != o.value);
	}

	@Override
	public int intValue() {
		return this.value;
	}

	@Override
	public long longValue() {
		return this.value;
	}

	@Override
	public float floatValue() {
		return (float) this.value;
	}

	@Override
	public double doubleValue() {
		return this.value;
	}

	public BInteger plus(BInteger o) {
		return of(Math.addExact(this.value, o.value));
	}

	public String toString() {
		return String.valueOf(this.value);
	}

	public BInteger minus(BInteger o) {
		return of(Math.subtractExact(this.value, o.value));
	}

	public BInteger multiply(BInteger o) {
		return of(Math.multiplyExact(this.value, o.value));
	}

	public BInteger power(BInteger exp) {
		int pow = exp.value;
		if (pow < 0) {
			throw new IllegalArgumentException("Exponent must be a natural number");
		}

		int val = this.value;
		if (pow == 0 || val == 1) {
			return ONE;
		} else if (val == 0) {
			return ZERO;
		}

		int result = 1;
		while (pow > 0) {
			if (pow % 2 == 1) {
				result = Math.multiplyExact(result, val);
			}

			val = Math.multiplyExact(val, val);
			pow /= 2; // safe division
		}

		return of(result);
	}

	public BInteger divide(BInteger o) {
		// divideExact got added in Java 18
		int x = this.value;
		int y = o.value;
		int q = x / y;
		if ((x & y & q) < 0) {
			throw new ArithmeticException("integer overflow");
		}
		return of(q);
	}

	public BInteger modulo(BInteger o) {
		return of(this.value % o.value);
	}

	public BInteger succ() {
		return of(Math.incrementExact(this.value));
	}

	public BInteger pred() {
		return of(Math.decrementExact(this.value));
	}

	public BInteger negative() {
		return of(Math.negateExact(this.value));
	}

	public BInteger positive() {
		return this;
	}

	public BBoolean isInteger() {
		return BBoolean.TRUE;
	}

	public BBoolean isNotInteger() {
		return BBoolean.FALSE;
	}

	public BBoolean isNatural() {
		return this.greaterEqual(ZERO);
	}

	public BBoolean isNotNatural() {
		return isNatural().not();
	}

	public BBoolean isNatural1() {
		return this.greater(ZERO);
	}

	public BBoolean isNotNatural1() {
		return isNatural1().not();
	}
}
