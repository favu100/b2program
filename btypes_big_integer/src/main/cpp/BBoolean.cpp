#include <iostream>
#include <string>
#include "BObject.cpp"

using namespace std;


#ifndef BBOOLEAN_H
#define BBOOLEAN_H

class BBoolean : public BObject {
	private:
	    bool value;

    public:
        typedef BBoolean current_type;
        typedef void value_type;
        typedef void left_type;
        typedef void right_type;

    	BBoolean(bool val) {
    		value = val;
    	}

    	BBoolean(){};

    	BBoolean(const BBoolean& val) {
    	    value = val.value;
    	}

    	static string toString(bool b) {
    		return b ? "true" : "false";
    	}

	    bool booleanValue() const {
		    return value;
	    }

        BBoolean _or(const BBoolean& other) const {
            return value || other.value;
        }

        BBoolean _or(bool other) const {
            return value || other;
        }

        BBoolean _xor(const BBoolean& other) const {
            return value ^ other.value;
        }

        BBoolean _xor(bool other) const {
            return value ^ other;
        }

        BBoolean _and(const BBoolean& other) const {
            return value && other.value;
        }

        BBoolean _and(bool other) const {
            return value && other;
        }

        BBoolean _not() const {
            return !value;
        }

        BBoolean implies(const BBoolean& other) const {
            return !value || other.value;
        }

        BBoolean implies(bool other) const {
            return !value || other;
        }

        BBoolean equivalent(bool other) const {
            return value == other;
        }

        BBoolean equivalent(const BBoolean& other) const {
            return value == other.value;
        }

        BBoolean equal(const BBoolean& other) const {
            return value == other.value;
        }

        BBoolean unequal(const BBoolean& other) const {
            return value != other.value;
        }

        friend bool operator !=(const BBoolean& o1, const BBoolean& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BBoolean& o1, const BBoolean& o2) {
            return o1.value == o2.value;
        }

        bool operator <(const BBoolean& other) {
            return value != other.value;
        }

        void operator =(const BBoolean& other) {
            value = other.value;
        }

        int hashCode() const {
            return value == true ? 1 : 0;
        }

        friend std::ostream& operator<<(std::ostream &strm, const BBoolean &b) {
          return strm << toString(b.value);
        }
};
#endif