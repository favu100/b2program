import {BSet} from "./BSet.js";
import {BBoolean} from "./BBoolean.js";

export class BUtils {
    static readonly BOOL: BSet<BBoolean>  = new BSet<BBoolean>(new BBoolean(true), new BBoolean(false));
}

export class SelectError extends Error {
    constructor(msg: string) {
        super(msg);
        Object.setPrototypeOf(this, SelectError.prototype);
    }
}

export class VariantViolation extends Error {
    constructor(msg: string) {
        super(msg);
        Object.setPrototypeOf(this, SelectError.prototype);
    }
}

export class LoopInvariantViolation extends Error {
    constructor(msg: string) {
        super(msg);
        Object.setPrototypeOf(this, SelectError.prototype);
    }
}