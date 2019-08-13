#include <iostream>
#include <string>
#include "BInteger.hpp"


BInteger::BInteger(const int& val) {
    value = val;
}

int BInteger::intValue() const {
    return value;
}

BInteger::BInteger(){};

BInteger::BInteger(const BInteger& val) {
    value = val.value;
}

int BInteger::compareTo(const BInteger& o) const {
    return value - o.value;
}

BBoolean BInteger::lessEqual(const BInteger& o) const {
    return compareTo(o) <= 0;
}

BBoolean BInteger::greaterEqual(const BInteger& o) const {
    return compareTo(o) >= 0;
}

BBoolean BInteger::less(const BInteger& o) const {
    return compareTo(o) < 0;
}

BBoolean BInteger::greater(const BInteger& o) const {
    return compareTo(o) > 0;
}

BBoolean BInteger::equal(const BInteger& o) const {
    return compareTo(o) == 0;
}

BBoolean BInteger::unequal(const BInteger& o) const {
    return compareTo(o) != 0;
}

BInteger BInteger::plus(const BInteger& o) const {
    return value + o.value;
}

BInteger BInteger::minus(const BInteger& o) const {
    return value - o.value;
}

BInteger BInteger::multiply(const BInteger& o) const {
    return value * o.value;
}

BInteger BInteger::power(const BInteger& o) const {
    return value ^ o.value;
}

BInteger BInteger::divide(const BInteger& o) const {
    return value / o.value;
}

BInteger BInteger::modulo(const BInteger& o) const {
    return value % o.value;
}

BInteger BInteger::succ() const {
    return value + 1;
}

BInteger BInteger::pred() const {
    return value - 1;
}

BInteger BInteger::negative() const {
    return -value;
}

BInteger BInteger::positive() const {
    return *this;
}

void BInteger::operator =(const BInteger& other) {
    this->value = other.value;
}

int BInteger::hashCode() const {
    int prime = 31;
    int result = 1;
    result = prime * result + value;
    return result;
}

BBoolean BInteger::isInteger() {
    return BBoolean(true);
}

BBoolean BInteger::isNotInteger() {
    return BBoolean(false);
}

BBoolean BInteger::isNatural() {
    return this->greaterEqual(BInteger(0));
}

BBoolean BInteger::isNotNatural() {
    return this->isNatural()._not();
}

BBoolean BInteger::isNatural1() {
    return this->greater(BInteger(0));
}

BBoolean BInteger::isNotNatural1() {
    return this->isNatural1()._not();
}