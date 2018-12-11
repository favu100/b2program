package de.hhu.stups.btypes;


import clojure.lang.BigInt;
import clojure.lang.RT;
import clojure.lang.Var;

public class BInteger extends BNumber {

	private static final Var PLUS = RT.var("clojure.core", "+");

	private static final Var MINUS = RT.var("clojure.core", "-");

	private static final Var MULTIPLY = RT.var("clojure.core", "*");

	private static final Var DIVIDE = RT.var("clojure.core", "quot");

	private static final Var MODULO = RT.var("clojure.core", "mod");

	private static final Var COMPARE = RT.var("clojure.core", "compare");

	public static final Var INC = RT.var("clojure.core", "inc");

	private static final Var DEC = RT.var("clojure.core", "dec");

	private static final Var POWER = RT.var("clojure.core", "^");

	private static final Var BIGINT = RT.var("clojure.core", "bigint");

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (obj instanceof BNumber) {
			//TODO: other numbers
			return this.compareTo((BNumber) obj) == 0;
		}
		// assert getClass() != obj.getClass()
		return false;
	}

	private static final long serialVersionUID = -6484548796859331267L;
	private BigInt value;

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((value == null) ? 0 : value.hashCode());
		return result;
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

	public int compareTo(BNumber o) {
		BInteger other = (BInteger) o;
		return (int) COMPARE.invoke(this.value, other.value);
	}

	public BBoolean lessEqual(BNumber o) {
		return new BBoolean(compareTo(o) <= 0);
	}


	public BBoolean greaterEqual(BNumber o) {
		return new BBoolean(compareTo(o) >= 0);
	}

	public BBoolean less(BNumber o) {
		return new BBoolean(compareTo(o) < 0);
	}

	public BBoolean greater(BNumber o) {
		return new BBoolean(compareTo(o) > 0);
	}

	public BBoolean equal(BNumber o) {
		return new BBoolean(compareTo(o) == 0);
	}

	public BBoolean unequal(BNumber o) {
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

	@Override
	public BNumber plus(BNumber o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) PLUS.invoke(this.value, other.value));
	}

	public java.lang.String toString() {
		return this.value.toString();
	}

	@Override
	public BNumber minus(BNumber o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) MINUS.invoke(this.value, other.value));
	}

	@Override
	public BNumber multiply(BNumber o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) MULTIPLY.invoke(this.value, other.value));
	}

	@Override
	public BNumber power(BNumber o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) POWER.invoke(this.value, other.value));
	}

	@Override
	public BNumber divide(BNumber o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) DIVIDE.invoke(this.value, other.value));
	}

	@Override
	public BNumber modulo(BNumber o) {
		BInteger other = (BInteger) o;
		return new BInteger((BigInt) MODULO.invoke(this.value, other.value));
	}

	@Override
	public BNumber next() {
		return new BInteger((BigInt) INC.invoke(this.value));
	}

	@Override
	public BNumber previous() {
		return new BInteger((BigInt) DEC.invoke(this.value));
	}

	@Override
	public BNumber leftShift(BNumber o) {
		return null;
	}

	@Override
	public BNumber rightShift(BNumber o) {
		return null;
	}

	@Override
	public boolean isCase(BNumber o) {
		return this.equals(o);
	}

	@Override
	public BNumber negative() {
		return new BInteger((BigInt) MINUS.invoke(this.value));
	}

	@Override
	public BNumber positive() {
		return this;
	}

	public BigInt getValue() {
		return value;
	}
}