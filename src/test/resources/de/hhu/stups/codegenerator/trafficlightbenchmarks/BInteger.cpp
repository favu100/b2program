#include <iostream>
#include <string>
#include "BBoolean.cpp"

#ifndef BINTEGER_H
#define BINTEGER_H

using namespace std;

class BInteger : public BObject {
	private:
	    int value;

    public:

        typedef BInteger current_type;
        typedef void value_type;
        typedef void left_type;
        typedef void right_type;

        BInteger(const int& val) {
            value = val;
        }

        int intValue() const {
            return value;
        }

        BInteger(){};

        BInteger(const BInteger& val) {
            value = val.value;
        }

        int compareTo(const BInteger& o) const {
            return value - o.value;
        }

        BBoolean lessEqual(const BInteger& o) const {
            return compareTo(o) <= 0;
        }


        BBoolean greaterEqual(const BInteger& o) const {
            return compareTo(o) >= 0;
        }

        BBoolean less(const BInteger& o) const {
            return compareTo(o) < 0;
        }

        BBoolean greater(const BInteger& o) const {
            return compareTo(o) > 0;
        }

        BBoolean equal(const BInteger& o) const {
            return compareTo(o) == 0;
        }

        BBoolean unequal(const BInteger& o) const {
            return compareTo(o) != 0;
        }

        BInteger plus(const BInteger& o) const {
            return value + o.value;
        }

        BInteger minus(const BInteger& o) const {
            return value - o.value;
        }

        BInteger multiply(const BInteger& o) const {
            return value * o.value;
        }

        BInteger power(const BInteger& o) const {
            return value ^ o.value;
        }

        BInteger divide(const BInteger& o) const {
            return value / o.value;
        }

        BInteger modulo(const BInteger& o) const {
            return value % o.value;
        }
        BInteger succ() const {
            return value + 1;
        }

        BInteger pred() const {
            return value - 1;
        }

        BInteger negative() const {
            return -value;
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
            this->value = other.value;
        }

        int hashCode() const {
            int prime = 31;
            int result = 1;
            result = prime * result + value;
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const BInteger &b) {
          return strm << b.value;
        }

        BBoolean isInteger() {
            return BBoolean(true);
        }

        BBoolean isNotInteger() {
            return BBoolean(false);
        }

        BBoolean isNatural() {
            return this->greaterEqual(BInteger(0));
        }

        BBoolean isNotNatural() {
            return this->isNatural()._not();
        }

        BBoolean isNatural1() {
            return this->greater(BInteger(0));
        }

        BBoolean isNotNatural1() {
            return this->isNatural1()._not();
        }
};
#endif