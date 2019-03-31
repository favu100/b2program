#include <iostream>
#include <string>
#include "BBoolean.cpp"

using namespace std;

#ifndef BCOUPLE_H
#define BCOUPLE_H

template<typename S, typename T>
class BCouple : public BObject {

	private:
	    S lhs;
	    T rhs;

	public:

        BCouple(const S& l, const T& r) {
            lhs = l;
            rhs = r;
        }

        BCouple(){}

        S projection1() {
            return lhs;
        }

        T projection2() {
            return rhs;
        }

        BBoolean equal(const BCouple& other) {
            return lhs == other.lhs && rhs == other.rhs;
        }

        BBoolean unequal(const BCouple& other) {
            return lhs != other.lhs || rhs != other.rhs;
        }

        friend bool operator ==(const BCouple<S,T>& o1, const BCouple<S,T>& o2) {
            return o1.lhs == o2.lhs && o1.rhs == o2.rhs;
        }

        friend bool operator !=(const BCouple<S,T>& o1, const BCouple<S,T>& o2) {
            return o1.lhs != o2.lhs || o1.rhs != o2.rhs;
        }

        void operator =(const BCouple<S,T>& other) {
            this->lhs = other.lhs;
            this->rhs = other.rhs;
        }

        int hashCode() const {
            return 0;
        }

        /*BCouple operator() {
            return *this;
        }*/

	/*public boolean equals(Object o) {
		if (this == o) {
			return true;
		}
		if (o == null || getClass() != o.getClass()) {
			return false;
		}

        BCouple bObjects = (BCouple) o;
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