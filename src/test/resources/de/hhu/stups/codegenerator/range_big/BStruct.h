#include "BBoolean.h"

#ifndef BSTRUCT_H
#define BSTRUCT_H

class BStruct {

    public:

        friend bool operator !=(const BStruct& p1, const BStruct& p2);

        friend bool operator ==(const BStruct& p1, const BStruct& p2);

        virtual int hashCode() {
            return 0;
        };

        BBoolean isRecord();

        BBoolean isNotRecord();
};
#endif