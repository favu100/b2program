package de.hhu.stups.btypes;

import java.math.BigInteger;

public class BInteger extends java.lang.Number implements Comparable<BInteger>, BObject {

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (obj instanceof java.lang.Number) {
			return this.compareTo((java.lang.Number) obj) == 0;
		}
		// assert getClass() != obj.getClass()
		return false;
	}

	private static final long serialVersionUID = -6484548796859331267L;
	private java.math.BigInteger value;

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((value == null) ? 0 : value.hashCode());
		return result;
	}

	public BInteger(String value) {
		this.value = new java.math.BigInteger(value);
	}

    public BInteger(java.math.BigInteger value) {
		this.value = value;
	}

	public static BInteger build(int value) {
		return new BInteger(String.valueOf(value));
	}

	public int compareTo(BInteger o) {
		return this.value.compareTo(o.asBigInteger());
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


	public int compareTo(java.lang.Number o) {
		java.math.BigInteger oi;
		if (o == null) {
			throw new NullPointerException();
		}
		if (getClass() != o.getClass()) {
			oi = new java.math.BigInteger(java.lang.String.valueOf(o.longValue()));
		} else {
            BInteger oo = (BInteger) o;
			oi = oo.value;
		}
		return this.value.compareTo(oi);
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
		return new BInteger(this.value.add(o.asBigInteger()));
	}

	public java.math.BigInteger asBigInteger() {
		return this.value;
	}

	public java.lang.String toString() {
		return this.value.toString();
	}

	public BInteger minus(BInteger o) {
		return new BInteger(this.value.subtract(o.asBigInteger()));
	}

	public BInteger multiply(BInteger o) {
		return new BInteger(this.value.multiply(o.asBigInteger()));
	}

	public BInteger power(BInteger o) {
		return new BInteger(this.value.pow(o.intValue()));
	}

	public BInteger divide(BInteger o) {
		return new BInteger(this.value.divide(o.asBigInteger()));
	}

	public BInteger modulo(BInteger o) {
		return new BInteger(this.value.mod(o.asBigInteger()));
	}

	public BInteger or(BInteger o) {
		return new BInteger(this.value.or(o.asBigInteger()));
	}

	public BInteger and(BInteger o) {
		return new BInteger(this.value.and(o.asBigInteger()));
	}

	public BInteger xor(BInteger o) {
		return new BInteger(this.value.xor(o.asBigInteger()));
	}

	public BInteger next() {
		return new BInteger(this.value.add(new java.math.BigInteger("1")));
	}

	public BInteger previous() {
		return new BInteger(this.value.subtract(new java.math.BigInteger("1")));
	}

	public BInteger leftShift(BInteger o) {
		return new BInteger(this.value.shiftLeft(o.intValue()));
	}

	public BInteger rightShift(BInteger o) {
		return new BInteger(this.value.shiftRight(o.intValue()));
	}

	public boolean isCase(BInteger o) {
		return this.equals(o);
	}

	public BInteger negative() {
		return new BInteger(this.value.negate());
	}

	public BInteger positive() {
		return this;
	}

	public BigInteger getValue() {
		return value;
	}
}
