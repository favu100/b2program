#include <typeinfo>
#ifndef BSTRUCT_H
#define BSTRUCT_H

class BStruct {

    public:

        friend bool operator !=(const BStruct& p1, const BStruct& p2);

        friend bool operator ==(const BStruct& p1, const BStruct& p2);

        virtual int hashCode() {
            return 0;
        };

        BBoolean isRecord() const {
            return BBoolean(true);
        }

        BBoolean isNotRecord() const {
            return BBoolean(false);
        }
};
#endif