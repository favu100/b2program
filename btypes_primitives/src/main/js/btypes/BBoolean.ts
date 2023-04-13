import {BObject} from "./BObject.js";

export class BBoolean implements BObject{
    readonly value: boolean;

    constructor(value: boolean | string | BBoolean) {
        if (typeof (value) === 'boolean') {
            this.value = value;
        } else if (typeof value === 'string') {
            this.value = value.toLowerCase() === 'true';
        } else {
            this.value = value.value;
        }
    }
    
    and(other: BBoolean): BBoolean {
        return new BBoolean(this.value && other.value)
    }

    or(other: BBoolean): BBoolean {
        return new BBoolean(this.value || other.value)
    }

    not(): BBoolean {
        return new BBoolean(!this.value)
    }

    implies(other: BBoolean): BBoolean {
        return this.not().or(other)
    }

    equivalent(other: BBoolean): BBoolean {
        return this.implies(other).and(other.implies(this))
    }

    equal(other: BBoolean): BBoolean {
        return new BBoolean(this.value === other.value);
    }

    equals(other: any): boolean {
        if (!(other instanceof BBoolean)) {
            return false;
        }
        return this.equal(other).booleanValue();
    }

    unequal(other: BBoolean): BBoolean {
        return new BBoolean(this.value != other.value);
    }

    booleanValue(): boolean {
        return this.value;
    }

    toString(): string {
        return this.value.toString();
    }

    hashCode(): number {
        return (31 * 1) ^ (this.value == true ? 1 : 0 << 1);
    }

}
