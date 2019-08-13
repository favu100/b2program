#include <iostream>
#include <string>
#include "BString.h"

BString::BString(std::string val) {
    value = val;
}

BString::BString(){};

BString::BString(const BString& val) {
    value = val.value;
}

BBoolean BString::equal(const BString& other) const {
    return value == other.value;
}

BBoolean BString::unequal(const BString& other) const {
    return value != other.value;
}

bool BString::operator <(const BString& other) {
    return value < other.value;
}

void BString::operator =(const BString& other) {
    value = other.value;
}

int BString::hashCode() const {
    return std::hash<std::string>()(value);
}

BBoolean BString::isString() {
    return BBoolean(true);
}

BBoolean BString::isNotString() {
    return BBoolean(false);
}