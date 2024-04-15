package de.hhu.stups.btypes;

import java.util.Objects;

import clojure.lang.BigInt;
import clojure.lang.RT;
import clojure.lang.Var;

public class BInteger extends java.lang.Number implements Comparable<BInteger>, BObject {

	private static final Var PLUS = RT.var("clojure.core", "+");

	private static final Var MINUS = RT.var("clojure.core", "-");

	private static final Var MULTIPLY = RT.var("clojure.core", "*");

	private static final Var DIVIDE = RT.var("clojure.core", "quot");

	private static final Var MODULO = RT.var("clojure.core", "mod");

	private static final Var COMPARE = RT.var("clojure.core", "compare");

	public static final Var INC = RT.var("clojure.core", "inc");

	private static final Var DEC = RT.var("clojure.core", "dec");

	private static final Var BIGINT = RT.var("clojure.core", "bigint");

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (obj instanceof BInteger) {
			return this.compareTo((BInteger) obj) == 0;
		}
		return false;
	}

	private static final long serialVersionUID = -6484548796859331267L;
	private BigInt value;

	@Override
	public int hashCode() {
		return Objects.hash(value);
	}

	public BInteger(String value) {
		try {
			this.value = BigInt.fromLong(Long.parseLong(value));
		} catch (NumberFormatException e) {
			this.value = BigInt.fromBigInteger(new java.math.BigInteger(value));
		}
	}

	public BInteger(BigInt value) {
		this.value = value;
	}

	public BInteger(int value) { new BInteger(String.valueOf(value)); }

	public static BInteger build(int value) {
		return new BInteger(String.valueOf(value));
	}

	public int compareTo(BInteger o) {
		BInteger other = (BInteger) o;
		return (int) COMPARE.invoke(this.value, other.value);
	}

	public BBoolean lessEqual(BInteger o) {
		return new BBoolean(compareTo(o) <= 0);
	}


	public BBoolean greaterEqual(BInteger o) {
		return new BBoolean(compareTo(o) >= 0);
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
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) PLUS.invoke(this.value, other.value));
	}

	public java.lang.String toString() {
		return this.value.toString();
	}

	public BInteger minus(BInteger o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) MINUS.invoke(this.value, other.value));
	}

	public BInteger multiply(BInteger o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) MULTIPLY.invoke(this.value, other.value));
	}

	public BInteger power(BInteger exp) {
		if(exp.equal(new BInteger("0")).booleanValue()) {
			return new BInteger("1");
		}
		BInteger tmp = power(exp.divide(new BInteger("2")));
		if(exp.modulo(new BInteger("2")).equal(new BInteger("0")).booleanValue()) {
			return tmp.multiply(tmp);
		} else {
			if(exp.greater(new BInteger("0")).booleanValue()) {
				return this.multiply(tmp.multiply(tmp));
			} else {
				return (tmp.multiply(tmp)).divide(this);
			}
		}
	}
	public BInteger divide(BInteger o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) DIVIDE.invoke(this.value, other.value));
	}

	public BInteger modulo(BInteger o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) MODULO.invoke(this.value, other.value));
	}

	public BInteger succ() {
		return new BInteger((BigInt) INC.invoke(this.value));
	}

	public BInteger pred() {
		return new BInteger((BigInt) DEC.invoke(this.value));
	}

	public BInteger leftShift(BInteger o) {
		return null;
	}

	public BInteger rightShift(BInteger o) {
		return null;
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
		return this.greaterEqual(new BInteger("0"));
	}

	public BBoolean isNotNatural() {
		return isNatural().not();
	}

	public BBoolean isNatural1() {
		return this.greater(new BInteger("0"));
	}

	public BBoolean isNotNatural1() {
		return isNatural1().not();
	}

	public BBoolean isInInterval(BInteger m, BInteger n) {
		return this.greaterEqual(m).and(this.lessEqual(n));
	}

	public BBoolean isNotInInterval(BInteger m, BInteger n) {
		return this.less(m).or(this.greater(n));
	}
}