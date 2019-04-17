#include <iostream>
#include <string>
#include "BBoolean.cpp"

using namespace std;

#ifndef BTUPLE_H
#define BTUPLE_H

template<typename S, typename T>
class BTuple : public BObject {

	private:
	    S lhs;
	    T rhs;

	public:
	    typedef void value_type;
        typedef S left_type;
        typedef T right_type;

        BTuple(const S& l, const T& r) {
            lhs = l;
            rhs = r;
        }

        BTuple(){}

        S projection1() {
            return lhs;
        }

        T projection2() {
            return rhs;
        }

        BBoolean equal(const BTuple& other) {
            return lhs == other.lhs && rhs == other.rhs;
        }

        BBoolean unequal(const BTuple& other) {
            return lhs != other.lhs || rhs != other.rhs;
        }

        friend bool operator ==(const BTuple<S,T>& o1, const BTuple<S,T>& o2) {
            return o1.lhs == o2.lhs && o1.rhs == o2.rhs;
        }

        friend bool operator !=(const BTuple<S,T>& o1, const BTuple<S,T>& o2) {
            return o1.lhs != o2.lhs || o1.rhs != o2.rhs;
        }

        void operator =(const BTuple<S,T>& other) {
            this->lhs = other.lhs;
            this->rhs = other.rhs;
        }

        int hashCode() const {
            return this->lhs.hashCode() ^ (this->rhs.hashCode() << 1);
        }

        friend std::ostream& operator<<(std::ostream &strm, const BTuple<S,T> &b) {
          return strm << "(" << b.lhs << " |-> " << b.rhs << ")";
        }

        /*BTuple operator() {
            return *this;
        }*/

	/*public boolean equals(Object o) {
		if (this == o) {
			return true;
		}
		if (o == null || getClass() != o.getClass()) {
			return false;
		}

        BTuple bObjects = (BTuple) o;
		// elements is never null
		return bObjects.getFirst().equals(this.first) && bObjects.getSecond().equals(this.second);
	}

	public int hashCode() {
		return Objects.hash(first, second);
	}

	@Override
	public java.lang.String toString() {
		return "(" + this.getFirst() + " |-> " + this.getSecond() + ')';
	}*/

};
#endif