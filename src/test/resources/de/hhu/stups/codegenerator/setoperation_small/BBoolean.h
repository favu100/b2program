#include <string>

#include "BObject.h"


#ifndef BBOOLEAN_H
#define BBOOLEAN_H

class BBoolean: public BObject {

	private:
	    bool value;

    public:

        typedef BBoolean current_type;
        typedef void value_type;
        typedef void left_type;
        typedef void right_type;

    	BBoolean(bool val);

    	BBoolean();

    	BBoolean(const BBoolean& val);

    	static std::string toString(bool b) {
    	    return b ? "true" : "false";
    	}

	    bool booleanValue() const;

        BBoolean _or(const BBoolean& other) const;

        BBoolean _or(bool other) const;

        BBoolean _xor(const BBoolean& other) const;

        BBoolean _xor(bool other) const;

        BBoolean _and(const BBoolean& other) const;

        BBoolean _and(bool other) const;

        BBoolean _not() const;

        BBoolean implies(const BBoolean& other) const;

        BBoolean implies(bool other) const;

        BBoolean equivalent(bool other) const;

        BBoolean equivalent(const BBoolean& other) const;

        BBoolean equal(const BBoolean& other) const;

        BBoolean unequal(const BBoolean& other) const;

        friend bool operator !=(const BBoolean& o1, const BBoolean& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BBoolean& o1, const BBoolean& o2) {
            return o1.value == o2.value;
        }

        bool operator <(const BBoolean& other);

        void operator =(const BBoolean& other);

        int hashCode() const;

        friend std::ostream& operator<<(std::ostream &strm, const BBoolean &b) {
            return strm << toString(b.value);
        }

};
#endif