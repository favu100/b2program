#include "BStruct.h"


BBoolean BStruct::isRecord() {
    return BBoolean(true);
}

BBoolean BStruct::isNotRecord() {
    return BBoolean(false);
}