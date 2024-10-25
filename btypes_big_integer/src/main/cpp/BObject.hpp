#include <typeinfo>
#ifndef BOBJECT_H
#define BOBJECT_H

class BObject {

    public:

	    typedef BTuple<S,T> current_type;
	    typedef void value_type;
        typedef S left_type;
        typedef T right_type;

        friend bool operator !=(const BObject& p1, const BObject& p2) {return true;} // This is only used for untyped empty sets. This function is overridden in sub-classes.

        friend bool operator ==(const BObject& p1, const BObject& p2) {return false;} // This is only used for untyped empty sets. This function is overridden in sub-classes.

        virtual int hashCode() const {
            return 0;
        };
};
#endif