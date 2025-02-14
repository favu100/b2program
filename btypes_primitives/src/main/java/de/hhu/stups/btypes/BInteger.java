package de.hhu.stups.btypes;

import java.math.BigInteger;

public final class BInteger extends java.lang.Number implements Comparable<BInteger>, BObject {

    public static final BInteger ZERO = new BInteger(0);
    public static final BInteger ONE = new BInteger(1);
    public static final BInteger TWO = new BInteger(2);

    private static final long serialVersionUID = -6484548796859331267L;
    private final int value;

    public BInteger(int value) {
        this.value = value;
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
            return this.value == ((BInteger) obj).value;
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
        return new BBoolean(this.value <= o.value);
    }

    public BBoolean greaterEqual(BInteger o) {
        return new BBoolean(this.value >= o.value);
    }

    public java.math.BigInteger asBigInteger() {
        return BigInteger.valueOf(value);
    }

    public BBoolean less(BInteger o) {
        return new BBoolean(this.value < o.value);
    }

    public BBoolean greater(BInteger o) {
        return new BBoolean(this.value > o.value);
    }

    public BBoolean equal(BInteger o) {
        return new BBoolean(this.value == o.value);
    }

    public BBoolean unequal(BInteger o) {
        return new BBoolean(this.value != o.value);
    }

    @Override
    public int intValue() {
        return this.value;
    }

    @Override
    public long longValue() {
        return (long) this.value;
    }

    @Override
    public float floatValue() {
        return (float) this.value;
    }

    @Override
    public double doubleValue() {
        return (double) this.value;
    }

    public BInteger plus(BInteger o) {
        return new BInteger(this.value + o.value);
    }

    public java.lang.String toString() {
        return String.valueOf(value);
    }

    public BInteger minus(BInteger o) {
        return new BInteger(this.value - o.value);
    }

    public BInteger multiply(BInteger o) {
        return new BInteger(this.value * o.value);
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
        return new BInteger(this.value / o.value);
    }

    public BInteger modulo(BInteger o) {
        return new BInteger(this.value % o.value);
    }

    public BInteger succ() {
        return new BInteger(this.value + 1);
    }

    public BInteger pred() {
        return new BInteger(this.value - 1);
    }

    public BInteger leftShift() {
        return new BInteger(this.value << 1);
    }

    public BInteger rightShift() {
        return new BInteger(this.value >> 1);
    }

    public boolean isCase(BInteger o) {
        return this.equals(o);
    }

    public BInteger negative() {
        return new BInteger(-this.value);
    }

    public BInteger positive() {
        return this;
    }

    public java.lang.Number getValue() {
        return value;
    }

    public BBoolean isInteger() {
        return new BBoolean(true);
    }

    public BBoolean isNotInteger() {
        return new BBoolean(false);
    }

    public BBoolean isNatural() {
        return this.greaterEqual(new BInteger(0));
    }

    public BBoolean isNotNatural() {
        return isNatural().not();
    }

    public BBoolean isNatural1() {
        return this.greater(new BInteger(0));
    }

    public BBoolean isNotNatural1() {
        return isNatural1().not();
    }
}
