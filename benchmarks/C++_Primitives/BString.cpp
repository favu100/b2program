#include <iostream>
#include <string>
#include "BObject.cpp"
#include "BBoolean.cpp"

using namespace std;


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

    	BString(std::string val) {
    		value = val;
    	}

    	BString(){};

    	BString(const BString& val) {
    	    value = val.value;
    	}

        BBoolean equal(const BString& other) const {
            return value == other.value;
        }

        BBoolean unequal(const BString& other) const {
            return value != other.value;
        }

        friend bool operator !=(const BString& o1, const BString& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BString& o1, const BString& o2) {
            return o1.value == o2.value;
        }

        bool operator <(const BString& other) {
            return value < other.value;
        }

        void operator =(const BString& other) {
            value = other.value;
        }

        int hashCode() const {
            return std::hash<std::string>()(value);
        }

        friend std::ostream& operator<<(std::ostream &strm, const BString &str) {
          return strm << str.value;
        }

        BBoolean isString() {
            return BBoolean(true);
        }

        BBoolean isNotString() {
            return BBoolean(false);
        }
};
#endif