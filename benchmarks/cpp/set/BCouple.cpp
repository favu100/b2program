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

        BCouple(S l, T r) {
            lhs = l;
            rhs = r;
        }

        BCouple(){}

        S getFirst() {
            return lhs;
        }

        T getSecond() {
            return rhs;
        }

        BBoolean operator ==(BCouple o) {
            return lhs == o.lhs && rhs == o.rhs;
        }

        BBoolean operator !=(BCouple o) {
            return lhs != o.lhs || rhs != o.rhs;
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