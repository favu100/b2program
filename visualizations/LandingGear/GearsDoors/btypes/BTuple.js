import { BBoolean } from "https://favu100.github.io/b2program/LandingGear/GearsDoors/btypes/BBoolean.js";
export class BTuple {
    constructor(first, second) {
        if (first == null || second == null) {
            throw new RangeError("Arguments of Tuple cant be null or undefined");
        }
        this.first = first;
        this.second = second;
    }
    equals(o) {
        if (o == null || !(o instanceof BTuple)) {
            return false;
        }
        return o.projection1().equals(this.first) && o.projection2().equals(this.second);
    }
    toString() {
        return "(" + this.projection1() + " |-> " + this.projection2() + ')';
    }
    projection1() {
        return this.first;
    }
    projection2() {
        return this.second;
    }
    equal(o) {
        return new BBoolean(this.equals(o));
    }
    unequal(o) {
        return new BBoolean(!this.equals(o));
    }
    hashCode() {
        return this.first.hashCode() ^ (this.second.hashCode() << 1);
    }
}
