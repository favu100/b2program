#include <typeinfo>
#ifndef BOBJECT_H
#define BOBJECT_H

class BObject {

    public:

        friend bool operator !=(const BObject& p1, const BObject& p2) {return true;} // This is only used for untyped empty sets. This function is overridden in sub-classes.

        friend bool operator ==(const BObject& p1, const BObject& p2) {return false;} // This is only used for untyped empty sets. This function is overridden in sub-classes.

        virtual int hashCode() const {
            return 0;
        };
};
#endif