#include <iostream>
#include <string>
#include "BBoolean.hpp"


BBoolean::BBoolean(bool val) {
    value = val;
}

BBoolean::BBoolean(){};

BBoolean::BBoolean(const BBoolean& val) {
    value = val.value;
}

bool BBoolean::booleanValue() const {
    return value;
}

BBoolean BBoolean::_or(const BBoolean& other) const {
    return value || other.value;
}

BBoolean BBoolean::_or(bool other) const {
    return value || other;
}

BBoolean BBoolean::_xor(const BBoolean& other) const {
    return value ^ other.value;
}

BBoolean BBoolean::_xor(bool other) const {
    return value ^ other;
}

BBoolean BBoolean::_and(const BBoolean& other) const {
    return value && other.value;
}

BBoolean BBoolean::_and(bool other) const {
    return value && other;
}

BBoolean BBoolean::_not() const {
    return !value;
}

BBoolean BBoolean::implies(const BBoolean& other) const {
    return !value || other.value;
}

BBoolean BBoolean::implies(bool other) const {
    return !value || other;
}

BBoolean BBoolean::equivalent(bool other) const {
    return value == other;
}

BBoolean BBoolean::equivalent(const BBoolean& other) const {
    return value == other.value;
}

BBoolean BBoolean::equal(const BBoolean& other) const {
    return value == other.value;
}

BBoolean BBoolean::unequal(const BBoolean& other) const {
    return value != other.value;
}

bool BBoolean::operator <(const BBoolean& other) {
    return value != other.value;
}

void BBoolean::operator =(const BBoolean& other) {
    value = other.value;
}

int BBoolean::hashCode() const {
    return value == true ? 1 : 0;
}