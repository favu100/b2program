#include <iostream>
#include <string>
#include "BBoolean.cpp"
#include "BigInt.hpp"

#ifndef BBIGINTEGER_H
#define BBIGINTEGER_H

using namespace std;

class BBigInteger : public BObject {

    /*
	@Override
	public boolean equals(Object obj) {
		if (== obj)
			return true;
		if (obj == null)
			return false;
		if (obj instanceof java.lang.Number) {
			return compareTo((java.lang.Number) obj) == 0;
		}
		// assert getClass() != obj.getClass()
		return false;
	}*/

	private:
	    BigInt value;

	/*@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((value == null) ? 0 : value.hashCode());
		return result;
	}*/

    public:
        /*BInteger(string val) {
            value = new java.math.BigInteger(val);
        }*/

        BBigInteger(const string& val) {
            value = BigInt(val);
        }

        BBigInteger(const BigInt& val) {
            value = val;
        }

        int intValue() const {
            return value.to_int();
        }

        BBigInteger(){};

        BBigInteger(const BBigInteger& val) {
            value = val.value;
        }

        BBoolean lessEqual(const BBigInteger& o) {
            return value <= o.value;
        }

        BBoolean greaterEqual(const BBigInteger& o) {
            return value >= o.value;
        }

        BBoolean less(const BBigInteger& o) {
            return value < o.value;
        }

        BBoolean greater(const BBigInteger& o) {
            return value > o.value;
        }

        BBoolean equal(const BBigInteger& o) {
            return value == o.value;
        }

        BBoolean unequal(const BBigInteger& o) {
            return value != o.value;
        }

        /*int compareTo(java.lang.Number o) {
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
            return value.compareTo(oi);
        }*/

        /*long longValue() {
            return value.longValue();
        }

        float floatValue() {
            return value.floatValue();
        }

        double doubleValue() {
            return value.doubleValue();
        }*/

        BBigInteger plus(const BBigInteger& o) {
            return value + o.value;
        }

        /*java.math.BigInteger asBigInteger() {
            return value;
        }

        java.lang.String toString() {
            return value.toString();
        }*/

        BBigInteger minus(const BBigInteger& o) {
            return value - o.value;
        }

        BBigInteger multiply(const BBigInteger& o) {
            return value * o.value;
        }

        BBigInteger divide(const BBigInteger& o) {
            return value / o.value;
        }

        BBigInteger modulo(const BBigInteger& o) {
            return value % o.value;
        }

        /*BInteger or(BInteger o) {
            return new BInteger(value.or(o.value));
        }

        BInteger and(BInteger o) {
            return new BInteger(value.and(o.value));
        }

        BInteger xor(BInteger o) {
            return new BInteger(value.xor(o.value));
        }*/

        BBigInteger next() {
            return value + 1;
        }

        BBigInteger previous() {
            return value - 1;
        }

        /*BInteger leftShift(BInteger o) {
            return new BInteger(value.shiftLeft(o.intValue()));
        }

        BInteger rightShift(BInteger o) {
            return new BInteger(value.shiftRight(o.intValue()));
        }

        boolean isCase(BInteger o) {
            return equals(o);
        }*/

        BBigInteger negative() {
            return -value;
        }

        BBigInteger positive() {
            return *this;
        }

        /*BInteger operator=(BInteger other) {
            this->value = other.value;
            return *this;
        }*/

        friend bool operator !=(const BBigInteger& o1, const BBigInteger& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BBigInteger& o1, const BBigInteger& o2) {
            return o1.value == o2.value;
        }

        void operator =(const BBigInteger& other) {
            value = other.value;
        }

        int hashCode() const {
            int prime = 31;
            int result = 1;
            result = prime * result + value.to_int();
            return result;
        }

};
#endif