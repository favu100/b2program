#include "BObject.h"
#include "BBoolean.h"


#ifndef BSTRING_H
#define BSTRING_H

class BString : public BObject {

	private:
	    std::string value;

    public:

        typedef BString current_type;
        typedef void value_type;
        typedef void left_type;
        typedef void right_type;

    	BString(std::string val);

    	BString();

    	BString(const BString& val);

        BBoolean equal(const BString& other) const;

        BBoolean unequal(const BString& other) const;

        friend bool operator !=(const BString& o1, const BString& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BString& o1, const BString& o2) {
            return o1.value == o2.value;
        }

        bool operator <(const BString& other);

        void operator =(const BString& other);

        int hashCode() const;

        friend std::ostream& operator<<(std::ostream &strm, const BString &str) {
          return strm << str.value;
        }

        BBoolean isString();

        BBoolean isNotString();
};
#endif