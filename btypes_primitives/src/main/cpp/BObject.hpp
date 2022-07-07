#include <typeinfo>
#ifndef BOBJECT_H
#define BOBJECT_H

class BObject {

    public:

        friend bool operator !=(const BObject& p1, const BObject& p2) {return true;}

        friend bool operator ==(const BObject& p1, const BObject& p2) {return false;}

        virtual int hashCode() const {
            return 0;
        };
};
#endif