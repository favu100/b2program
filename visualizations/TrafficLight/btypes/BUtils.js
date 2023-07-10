import { BSet } from "./BSet.js";
import { BBoolean } from "./BBoolean.js";
export class BUtils {
}
BUtils.BOOL = new BSet(new BBoolean(true), new BBoolean(false));
export class SelectError extends Error {
    constructor(msg) {
        super(msg);
        Object.setPrototypeOf(this, SelectError.prototype);
    }
}
