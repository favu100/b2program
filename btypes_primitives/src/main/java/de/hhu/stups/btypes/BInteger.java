package de.hhu.stups.btypes;

import java.util.Objects;

/**
 * Created by fabian on 15.10.18.
 */
public class BInteger extends java.lang.Number implements Comparable<BInteger>, BObject {


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
    private int value;

    @Override
    public int hashCode() {
        return Integer.hashCode(value);
    }

    public BInteger(int value) {
        this.value = value;
    }

    public static BInteger build(int value) {
        return new BInteger(value);
    }

    public int compareTo(BInteger o) {
        return this.value - o.value;
    }

    public BBoolean lessEqual(BInteger o) {
        return new BBoolean(compareTo(o) <= 0);
    }


    public BBoolean greaterEqual(BInteger o) {
        return new BBoolean(compareTo(o) >= 0);
    }

    public java.math.BigInteger asBigInteger() {
        return new java.math.BigInteger(String.valueOf(value));
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
        if(exp.intValue() == 0) {
            return new BInteger(1);
        }
        BInteger tmp = power(exp.divide(new BInteger(2)));
        if(exp.modulo(new BInteger(2)).equal(new BInteger(0)).booleanValue()) {
            return tmp.multiply(tmp);
        } else {
            if(exp.greater(new BInteger(0)).booleanValue()) {
                return this.multiply(tmp.multiply(tmp));
            } else {
                return (tmp.multiply(tmp)).divide(this);
            }
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

    public BBoolean isInInterval(BInteger m, BInteger n) {
        return this.greaterEqual(m).and(this.lessEqual(n));
    }

    public BBoolean isNotInInterval(BInteger m, BInteger n) {
        return this.less(m).or(this.greater(n));
    }


}