#include <iostream>
#include <string>
#include "BBoolean.hpp"
#include <gmpxx.h>

#ifndef BINTEGER_H
#define BINTEGER_H

using namespace std;

class BInteger : public BObject {

	private:
	    mpz_class value;

    public:
        typedef BInteger current_type;
        typedef void value_type;
        typedef void left_type;
        typedef void right_type;

        BInteger(const char* val) {
            value = val;
        }

        BInteger(const int& val) {
            value = val;
        }

        BInteger(const mpz_class& val) {
            value = val;
        }

        int intValue() const {
            return value.get_si();
        }

        BInteger(){};

        BInteger(const BInteger& val) {
            value = val.value;
        }


        BBoolean lessEqual(const BInteger& o) const {
            return value <= o.value;
        }

        BBoolean greaterEqual(const BInteger& o) const {
            return value >= o.value;
        }

        BBoolean less(const BInteger& o) const {
            return value < o.value;
        }

        BBoolean greater(const BInteger& o) const {
            return value > o.value;
        }

        BBoolean equal(const BInteger& o) const {
            return value == o.value;
        }

        BBoolean unequal(const BInteger& o) const {
            return value != o.value;
        }

        BInteger plus(const BInteger& o) const {
            return BInteger(value + o.value);
        }

        BInteger minus(const BInteger& o) const {
            return BInteger(value - o.value);
        }

        BInteger multiply(const BInteger& o) const {
            return BInteger(value * o.value);
        }

        BInteger divide(const BInteger& o) const {
            return BInteger(value / o.value);
        }

        BInteger modulo(const BInteger& o) const {
            return BInteger(value % o.value);
        }

        BInteger succ() const {
            return BInteger(value + 1);
        }

        BInteger pred() const {
            return BInteger(value - 1);
        }

        BInteger negative() const {
            return BInteger(-value);
        }

        BInteger positive() const {
            return *this;
        }

        friend bool operator !=(const BInteger& o1, const BInteger& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BInteger& o1, const BInteger& o2) {
            return o1.value == o2.value;
        }

        void operator =(const BInteger& other) {
            value = other.value;
        }

        int hashCode() const {
            int prime = 31;
            int result = 1;
            result = prime * result + value.get_si();
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const BInteger &b) {
          return strm << b.value;
        }

        BBoolean isInteger() const {
            return BBoolean(true);
        }

        BBoolean isNotInteger() const {
            return BBoolean(false);
        }

        BBoolean isNatural() const {
            return this->greaterEqual(BInteger(0));
        }

        BBoolean isNotNatural() const {
            return this->isNatural()._not();
        }

        BBoolean isNatural1() const {
            return this->greater(BInteger(0));
        }

        BBoolean isNotNatural1() const {
            return this->isNatural1()._not();
        }

};
#endif