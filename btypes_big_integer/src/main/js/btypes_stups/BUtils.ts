import {BSet} from "https://www3.hhu.de/stups/models/visb/btypes/BSet.js";
import {BBoolean} from "https://www3.hhu.de/stups/models/visb/btypes/BBoolean.js";

export class BUtils {
    static readonly BOOL: BSet<BBoolean>  = new BSet<BBoolean>(new BBoolean(true), new BBoolean(false));
}

export class SelectError extends Error {
    constructor(msg: string) {
        super(msg);
        Object.setPrototypeOf(this, SelectError.prototype);
    }
}

export class PreconditionOrAssertionViolation extends Error {
    constructor(msg: string) {
        super(msg);
        Object.setPrototypeOf(this, PreconditionOrAssertionViolation.prototype);
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