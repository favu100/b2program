package de.hhu.stups.btypes;

import java.util.Objects;

import clojure.lang.BigInt;
import clojure.lang.RT;
import clojure.lang.Var;

public final class BInteger extends java.lang.Number implements Comparable<BInteger>, BObject {

	public static final BInteger ZERO = new BInteger(0);
	public static final BInteger ONE = new BInteger(1);
	public static final BInteger TWO = new BInteger(2);

	private static final Var PLUS = RT.var("clojure.core", "+");
	private static final Var MINUS = RT.var("clojure.core", "-");
	private static final Var MULTIPLY = RT.var("clojure.core", "*");
	private static final Var DIVIDE = RT.var("clojure.core", "quot");
	private static final Var MODULO = RT.var("clojure.core", "mod");
	private static final Var COMPARE = RT.var("clojure.core", "compare");
	private static final Var INC = RT.var("clojure.core", "inc");
	private static final Var DEC = RT.var("clojure.core", "dec");
	private static final Var SHIFT_LEFT = RT.var("clojure.core", "bit-shift-left");
	private static final Var SHIFT_RIGHT = RT.var("clojure.core", "bit-shift-right");
	private static final long serialVersionUID = -6484548796859331267L;

	private final BigInt value;

	public BInteger(BigInt value) {
		this.value = Objects.requireNonNull(value, "value");
	}

	public BInteger(int value) {
		this(BigInt.fromLong(value));
	}

	public BInteger(String value) {
		BigInt parsed;
		try {
			parsed = BigInt.fromLong(Long.parseLong(value));
		} catch (NumberFormatException ignored) {
			parsed = BigInt.fromBigInteger(new java.math.BigInteger(value));
		}
		this.value = parsed;
	}

	public static BInteger build(int value) {
		return new BInteger(value);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		} else if (!(obj instanceof BInteger)) {
			return false;
		} else {
			return this.value.equals(((BInteger) obj).value);
		}
	}

	@Override
	public int hashCode() {
		return this.value.hashCode();
	}

	@Override
	public int compareTo(BInteger o) {
		return (int) COMPARE.invoke(this.value, o.value);
	}

	public BBoolean lessEqual(BInteger o) {
		return new BBoolean(compareTo(o) <= 0);
	}

	public BBoolean greaterEqual(BInteger o) {
		return new BBoolean(compareTo(o) >= 0);
	}

	public java.math.BigInteger asBigInteger() {
		return value.toBigInteger();
	}

	public BBoolean less(BInteger o) {
		return new BBoolean(compareTo(o) < 0);
	}

	public BBoolean greater(BInteger o) {
		return new BBoolean(compareTo(o) > 0);
	}

	public BBoolean equal(BInteger o) {
		return new BBoolean(compareTo(o) == 0);
	}

	public BBoolean unequal(BInteger o) {
		return new BBoolean(compareTo(o) != 0);
	}

	@Override
	public int intValue() {
		return this.value.intValue();
	}

	@Override
	public long longValue() {
		return this.value.longValue();
	}

	@Override
	public float floatValue() {
		return this.value.floatValue();
	}

	@Override
	public double doubleValue() {
		return this.value.doubleValue();
	}

	public BInteger plus(BInteger o) {
		return new BInteger((BigInt) PLUS.invoke(this.value, o.value));
	}

	public java.lang.String toString() {
		return this.value.toString();
	}

	public BInteger minus(BInteger o) {
		return new BInteger((BigInt) MINUS.invoke(this.value, o.value));
	}

	public BInteger multiply(BInteger o) {
		return new BInteger((BigInt) MULTIPLY.invoke(this.value, o.value));
	}

	public BInteger power(BInteger exp) {
		if (exp.isNotNatural().booleanValue()) {
			throw new IllegalArgumentException("Exponent must be a natural number");
		}

		BInteger result = ONE;
		while (true) {
			if (ONE.equals(exp.modulo(TWO))) {
				result = result.multiply(this);
			}

			exp = exp.divide(TWO);
			if (ZERO.equals(exp)) {
				return result;
			}

			result = result.multiply(result);
		}
	}

	public BInteger divide(BInteger o) {
        return new BInteger((BigInt) DIVIDE.invoke(this.value, o.value));
	}

	public BInteger modulo(BInteger o) {
		return new BInteger((BigInt) MODULO.invoke(this.value, o.value));
	}

	public BInteger succ() {
		return new BInteger((BigInt) INC.invoke(this.value));
	}

	public BInteger pred() {
		return new BInteger((BigInt) DEC.invoke(this.value));
	}

	public BInteger leftShift(BInteger o) {
		return new BInteger((BigInt) SHIFT_LEFT.invoke(this.value));
	}

	public BInteger rightShift(BInteger o) {
		return new BInteger((BigInt) SHIFT_RIGHT.invoke(this.value));
	}

	public boolean isCase(BInteger o) {
		return this.equals(o);
	}

	public BInteger negative() {
		return new BInteger((BigInt) MINUS.invoke(this.value));
	}

	public BInteger positive() {
		return this;
	}

	public BigInt getValue() {
		return value;
	}

	public BBoolean isInteger() {
		return new BBoolean(true);
	}

	public BBoolean isNotInteger() {
		return new BBoolean(false);
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
