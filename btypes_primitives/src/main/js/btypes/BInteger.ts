import {BBoolean} from './BBoolean.js';
import {BObject} from "./BObject.js";

export class BInteger implements BObject{

    value: number;

    constructor(value: number) {
        this.value = value;
    }

    equals(obj: any): boolean {
        if (obj instanceof BInteger) {
            return this.compareTo(obj) === 0;
        }
        return false;
    }

    static build(value: number): BInteger {
        return new BInteger(value);
    }

    compareTo(o: BInteger): number {
        return this.value - o.value;
    }

    lessEqual(o: BInteger): BBoolean {
        return new BBoolean(this.compareTo(o) <= 0);
    }


    greaterEqual(o: BInteger): BBoolean {
        return new BBoolean(this.compareTo(o) >= 0);
    }

    less(o: BInteger): BBoolean {
        return new BBoolean(this.compareTo(o) < 0);
    }

    greater(o: BInteger): BBoolean {
        return new BBoolean(this.compareTo(o) > 0);
    }

    equal(o: BInteger): BBoolean {
        return new BBoolean(this.compareTo(o) === 0);
    }

    unequal(o: BInteger): BBoolean {
        return new BBoolean(this.compareTo(o) != 0);
    }
    
    intValue(): number {
        return this.value;
    }

    plus(o: BInteger): BInteger {
        return new BInteger(this.value + o.value);
    }

    toString(): string {
        return this.value.toString();
    }

    minus(o: BInteger): BInteger {
        return new BInteger(this.value - o.value);
    }

    multiply(o: BInteger): BInteger {
        return new BInteger(this.value * o.value);
    }

    power(o: BInteger): BInteger {
        return new BInteger(this.value ^ o.value);
    }

    divide(o: BInteger): BInteger {
        return new BInteger(~~(this.value / o.value));
    }

    modulo(o: BInteger): BInteger {
        return new BInteger(this.value % o.value);
    }

    succ(): BInteger  {
        return new BInteger(this.value + 1);
    }

    pred(): BInteger  {
        return new BInteger(this.value - 1);
    }

    leftShift(): BInteger  {
        return new BInteger(this.value << 1);
    }

    rightShift(): BInteger  {
        return new BInteger(this.value >> 1);
    }

    isCase(o: BInteger): boolean {
        return this.equals(o);
    }

    negative(): BInteger  {
        return new BInteger(-this.value);
    }

    positive(): BInteger  {
        return this;
    }

    getValue(): number {
        return this.value;
    }

    isInteger(): BBoolean {
        return new BBoolean(true);
    }

    isNotInteger(): BBoolean {
        return new BBoolean(false);
    }

    isNatural(): BBoolean {
        return this.greaterEqual(new BInteger(0));
    }

    isNotNatural(): BBoolean {
        return this.isNatural().not();
    }

    isNatural1(): BBoolean {
        return this.greater(new BInteger(0));
    }

    isNotNatural1(): BBoolean {
        return this.isNatural1().not();
    }

    hashCode(): number {
        const prime = 31;
        let result = 1;
        result = prime * result + this.value;
        return result;
    }
}