#include <iostream>
#include <string>
#include "BInteger.h"
#include <gmpxx.h>


BInteger::BInteger(const char* val) {
    value = val;
}

BInteger::BInteger(const int& val) {
    value = val;
}

BInteger::BInteger(const mpz_class& val) {
    value = val;
}

int BInteger::intValue() const {
    return value.get_si();
}

BInteger::BInteger(){};

BInteger::BInteger(const BInteger& val) {
    value = val.value;
}

BBoolean BInteger::lessEqual(const BInteger& o) const {
    return value <= o.value;
}

BBoolean BInteger::greaterEqual(const BInteger& o) const {
    return value >= o.value;
}

BBoolean BInteger::less(const BInteger& o) const {
    return value < o.value;
}

BBoolean BInteger::greater(const BInteger& o) const {
    return value > o.value;
}

BBoolean BInteger::equal(const BInteger& o) const {
    return value == o.value;
}

BBoolean BInteger::unequal(const BInteger& o) const {
    return value != o.value;
}

BInteger BInteger::plus(const BInteger& o) const {
    return BInteger(value + o.value);
}

BInteger BInteger::minus(const BInteger& o) const {
    return BInteger(value - o.value);
}

BInteger BInteger::multiply(const BInteger& o) const {
    return BInteger(value * o.value);
}

BInteger BInteger::divide(const BInteger& o) const {
    return BInteger(value / o.value);
}

BInteger BInteger::modulo(const BInteger& o) const {
    return BInteger(value % o.value);
}

BInteger BInteger::succ() const {
    return BInteger(value + 1);
}

BInteger BInteger::pred() const {
    return BInteger(value - 1);
}

BInteger BInteger::negative() const {
    return BInteger(-value);
}

BInteger BInteger::positive() const {
    return *this;
}

void BInteger::operator =(const BInteger& other) {
    value = other.value;
}

int BInteger::hashCode() const {
    int prime = 31;
    int result = 1;
    result = prime * result + value.get_si();
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