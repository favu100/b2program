import { BBoolean } from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BBoolean.js";
export class BString {
    constructor(value) {
        this.value = value;
    }
    getValue() {
        return this.value;
    }
    equals(o) {
        if (o == null || o instanceof BString) {
            return false;
        }
        return this.value === o.value;
    }
    equal(o) {
        return new BBoolean(this.equals(o));
    }
    unequal(o) {
        return new BBoolean(!this.equals(o));
    }
    length() {
        return this.value.length;
    }
    isEmpty() {
        return this.value === "";
    }
    toString() {
        return '"' + this.value + '"';
    }
    isCase(o) {
        return this.value == o;
    }
    isString() {
        return new BBoolean(true);
    }
    isNotString() {
        return new BBoolean(false);
    }
    hashCode() {
        let hash = 0;
        if (this.value.length === 0) {
            return hash;
        }
        for (let i = 0; i < this.value.length; i++) {
            let chr = this.value.charCodeAt(i);
            hash = ((hash << 5) - hash) + chr;
            hash |= 0; // Convert to 32bit integer
        }
        return hash;
    }
    ;
}
