package de.hhu.stups.btypes;

import java.math.BigInteger;
import java.util.Objects;

import clojure.lang.BigInt;
import clojure.lang.RT;
import clojure.lang.Var;

public final class BInteger extends Number implements Comparable<BInteger>, BObject {

	private static final BigInteger JBI_ZERO = BigInteger.ZERO;
	private static final BigInteger JBI_ONE = BigInteger.ONE;
	private static final BigInteger JBI_TWO = BigInteger.valueOf(2);
	private static final BigInteger JBI_MINUS_ONE = BigInteger.valueOf(-1);

	private static final BigInt CBI_ZERO = BigInt.fromLong(0);
	private static final BigInt CBI_ONE = BigInt.fromLong(1);
	private static final BigInt CBI_TWO = BigInt.fromLong(2);
	private static final BigInt CBI_MINUS_ONE = BigInt.fromLong(-1);

	public static final BInteger ZERO = new BInteger(CBI_ZERO);
	public static final BInteger ONE = new BInteger(CBI_ONE);
	public static final BInteger TWO = new BInteger(CBI_TWO);
	public static final BInteger MINUS_ONE = new BInteger(CBI_MINUS_ONE);

	private static final Var PLUS = RT.var("clojure.core", "+");
	private static final Var MINUS = RT.var("clojure.core", "-");
	private static final Var MULTIPLY = RT.var("clojure.core", "*");
	private static final Var DIVIDE = RT.var("clojure.core", "quot");
	private static final Var MODULO = RT.var("clojure.core", "mod");
	private static final Var COMPARE = RT.var("clojure.core", "compare");
	private static final Var INC = RT.var("clojure.core", "inc");
	private static final Var DEC = RT.var("clojure.core", "dec");

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
				return new BInteger(BigInt.fromLong(value));
		}
	}

	public static BInteger of(long value) {
		if (value == 0) {
			return ZERO;
		} else if (value == 1) {
			return ONE;
		} else if (value == 2) {
			return TWO;
		} else if (value == -1) {
			return MINUS_ONE;
		} else {
			return new BInteger(BigInt.fromLong(value));
		}
	}

	public static BInteger of(BigInteger value) {
		if (JBI_ZERO.equals(value)) {
			return ZERO;
		} else if (JBI_ONE.equals(value)) {
			return ONE;
		} else if (JBI_TWO.equals(value)) {
			return TWO;
		} else if (JBI_MINUS_ONE.equals(value)) {
			return MINUS_ONE;
		} else {
			return new BInteger(BigInt.fromBigInteger(value));
		}
	}

	private static BInteger of(BigInt value) {
		if (CBI_ZERO.equals(value)) {
			return ZERO;
		} else if (CBI_ONE.equals(value)) {
			return ONE;
		} else if (CBI_TWO.equals(value)) {
			return TWO;
		} else if (CBI_MINUS_ONE.equals(value)) {
			return MINUS_ONE;
		} else {
			return new BInteger(value);
		}
	}

	public static BInteger of(String value) {
		return of(new BigInteger(value));
	}

	public static BInteger of(BInteger value) {
		return Objects.requireNonNull(value, "value");
	}

	private final BigInt value;

	private BInteger(BigInt value) {
		this.value = Objects.requireNonNull(value, "value");
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
		return BBoolean.of(compareTo(o) <= 0);
	}

	public BBoolean greaterEqual(BInteger o) {
		return BBoolean.of(compareTo(o) >= 0);
	}

	public BBoolean less(BInteger o) {
		return BBoolean.of(compareTo(o) < 0);
	}

	public BBoolean greater(BInteger o) {
		return BBoolean.of(compareTo(o) > 0);
	}

	public BBoolean equal(BInteger o) {
		return BBoolean.of(compareTo(o) == 0);
	}

	public BBoolean unequal(BInteger o) {
		return BBoolean.of(compareTo(o) != 0);
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
		return of((BigInt) PLUS.invoke(this.value, o.value));
	}

	public String toString() {
		return this.value.toString();
	}

	public BInteger minus(BInteger o) {
		return of((BigInt) MINUS.invoke(this.value, o.value));
	}

	public BInteger multiply(BInteger o) {
		return of((BigInt) MULTIPLY.invoke(this.value, o.value));
	}

	public BInteger power(BInteger exp) {
		if (exp.isNotNatural().booleanValue()) {
			throw new IllegalArgumentException("Exponent must be a natural number");
		}

		BInteger val = this;
		if (exp.equals(ZERO) || val.equals(ONE)) {
			return ONE;
		} else if (val.equals(ZERO)) {
			return ZERO;
		}

		BInteger result = ONE;
		while (exp.greater(ZERO).booleanValue()) {
			if (exp.modulo(TWO).equals(ONE)) {
				result = result.multiply(val);
			}

			val = val.multiply(val);
			exp = exp.divide(TWO);
		}

		return result;
	}

	public BInteger divide(BInteger o) {
		return of((BigInt) DIVIDE.invoke(this.value, o.value));
	}

	public BInteger modulo(BInteger o) {
		return of((BigInt) MODULO.invoke(this.value, o.value));
	}

	public BInteger succ() {
		return of((BigInt) INC.invoke(this.value));
	}

	public BInteger pred() {
		return of((BigInt) DEC.invoke(this.value));
	}

	public boolean isCase(BInteger o) {
		return this.equals(o);
	}

	public BInteger negative() {
		return of((BigInt) MINUS.invoke(this.value));
	}

	public BInteger positive() {
		return this;
	}

	public BBoolean isInteger() {
		return BBoolean.of(true);
	}

	public BBoolean isNotInteger() {
		return BBoolean.of(false);
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
