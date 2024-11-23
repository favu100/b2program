import { BBoolean } from './BBoolean.js';
export class BInteger {
    constructor(value) {
        this.value = value;
    }
    equals(obj) {
        if (obj instanceof BInteger) {
            return this.compareTo(obj) === 0;
        }
        return false;
    }
    static build(value) {
        return new BInteger(value);
    }
    compareTo(o) {
        return this.value - o.value;
    }
    lessEqual(o) {
        return new BBoolean(this.value <= o.value);
    }
    greaterEqual(o) {
        return new BBoolean(this.value >= o.value);
    }
    less(o) {
        return new BBoolean(this.value < o.value);
    }
    greater(o) {
        return new BBoolean(this.value > o.value);
    }
    equal(o) {
        return new BBoolean(this.value == o.value);
    }
    unequal(o) {
        return new BBoolean(this.value != o.value);
    }
    intValue() {
        return this.value;
    }
    plus(o) {
        return new BInteger(this.value + o.value);
    }
    toString() {
        return this.value.toString();
    }
    minus(o) {
        return new BInteger(this.value - o.value);
    }
    multiply(o) {
        return new BInteger(this.value * o.value);
    }
    power(o) {
        return new BInteger(Math.pow(this.value, o.value));
    }
    divide(o) {
        return new BInteger(~~(this.value / o.value));
    }
    modulo(o) {
        return new BInteger(this.value % o.value);
    }
    succ() {
        return new BInteger(this.value + 1);
    }
    pred() {
        return new BInteger(this.value - 1);
    }
    leftShift() {
        return new BInteger(this.value << 1);
    }
    rightShift() {
        return new BInteger(this.value >> 1);
    }
    isCase(o) {
        return this.equals(o);
    }
    negative() {
        return new BInteger(-this.value);
    }
    positive() {
        return this;
    }
    getValue() {
        return this.value;
    }
    isInteger() {
        return new BBoolean(true);
    }
    isNotInteger() {
        return new BBoolean(false);
    }
    isNatural() {
        return this.greaterEqual(new BInteger(0));
    }
    isNotNatural() {
        return this.isNatural().not();
    }
    isNatural1() {
        return this.greater(new BInteger(0));
    }
    isNotNatural1() {
        return this.isNatural1().not();
    }
    hashCode() {
        const prime = 31;
        let result = 1;
        result = prime * result + this.value;
        return result;
    }
}
