#include <iostream>
#include <string>
#include "BBoolean.cpp"
#include <gmpxx.h>

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
	    mpz_t value;

	/*@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((value == null) ? 0 : value.hashCode());
		return result;
	}*/

    public:

        BBigInteger(const char* val) {
            mpz_init_set_str(value, val, 10);
        }

        BBigInteger(const mpz_t& val) {
            mpz_init_set(value, val);
        }

        int intValue() const {
            return mpz_get_si(value);
        }

        BBigInteger(){};

        BBigInteger(const BBigInteger& val) {
            mpz_init_set(value, val.value);
        }

        int compareTo(const BBigInteger& o) {
            return mpz_cmp(value, o.value);
        }


        BBoolean lessEqual(const BBigInteger& o) {
            return compareTo(o) <= 0;
        }

        BBoolean greaterEqual(const BBigInteger& o) {
            return compareTo(o) >= 0;
        }

        BBoolean less(const BBigInteger& o) {
            return compareTo(o) < 0;
        }

        BBoolean greater(const BBigInteger& o) {
            return compareTo(o) > 0;
        }

        BBoolean equal(const BBigInteger& o) {
            return compareTo(o) == 0;
        }

        BBoolean unequal(const BBigInteger& o) {
            return compareTo(o) != 0;
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
            mpz_t result;
            mpz_init(result);
            mpz_add(result, value, o.value);
            return result;
        }

        /*java.math.BigInteger asBigInteger() {
            return value;
        }

        java.lang.String toString() {
            return value.toString();
        }*/

        BBigInteger minus(const BBigInteger& o) {
            mpz_t result;
            mpz_init(result);
            mpz_sub(result, value, o.value);
            return result;
        }

        BBigInteger multiply(const BBigInteger& o) {
            mpz_t result;
            mpz_init(result);
            mpz_mul(result, value, o.value);
            return result;
        }

        BBigInteger divide(const BBigInteger& o) {
            mpz_t result;
            mpz_init(result);
            mpz_div(result, value, o.value);
            return result;
        }

        BBigInteger modulo(const BBigInteger& o) {
            mpz_t result;
            mpz_init(result);
            mpz_mod(result, value, o.value);
            return result;
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
            mpz_t result;
            mpz_t one;
            mpz_init(result);
            mpz_init_set_str(one, "1", 10);
            mpz_add(result, value, one);
            return result;
        }

        BBigInteger previous() {
            mpz_t result;
            mpz_t one;
            mpz_init(result);
            mpz_init_set_str(one, "1", 10);
            mpz_sub(result, value, one);
            return result;
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
            mpz_t result;
            mpz_init(result);
            mpz_neg(result, value);
            return result;
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
            mpz_init_set(value, other.value);
        }

        int hashCode() const {
            int prime = 31;
            int result = 1;
            result = prime * result + mpz_get_si(value);
            return result;
        }

};
#endif