#include <string>
#include "BBoolean.hpp"

#ifndef BINTEGER_H
#define BINTEGER_H

class BInteger : public BObject {
	private:
	    int value;

    public:

        typedef BInteger current_type;
        typedef void value_type;
        typedef void left_type;
        typedef void right_type;

        BInteger(const int& val);

        int intValue() const;

        BInteger();

        BInteger(const BInteger& val);

        int compareTo(const BInteger& o) const;

        BBoolean lessEqual(const BInteger& o) const;


        BBoolean greaterEqual(const BInteger& o) const;

        BBoolean less(const BInteger& o) const;

        BBoolean greater(const BInteger& o) const;

        BBoolean equal(const BInteger& o) const;

        BBoolean unequal(const BInteger& o) const;

        BInteger plus(const BInteger& o) const;

        BInteger minus(const BInteger& o) const;

        BInteger multiply(const BInteger& o) const;

        BInteger power(const BInteger& o) const;

        BInteger divide(const BInteger& o) const;

        BInteger modulo(const BInteger& o) const;

        BInteger succ() const;

        BInteger pred() const;

        BInteger negative() const;

        BInteger positive() const;

        friend bool operator !=(const BInteger& o1, const BInteger& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BInteger& o1, const BInteger& o2) {
            return o1.value == o2.value;
        }

        void operator =(const BInteger& other);

        int hashCode() const;

        friend std::ostream& operator<<(std::ostream &strm, const BInteger &b) {
          return strm << b.value;
        }

        BBoolean isInteger();

        BBoolean isNotInteger();

        BBoolean isNatural();

        BBoolean isNotNatural();

        BBoolean isNatural1();

        BBoolean isNotNatural1();
};
#endif