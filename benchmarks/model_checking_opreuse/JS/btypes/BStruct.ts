import {BObject} from "./BObject.js";
import {BBoolean} from "./BBoolean.js";

export abstract class BStruct implements BObject {

    isRecord(): BBoolean {
        return new BBoolean(true);
    }

    isNotRecord(): BBoolean {
        return new BBoolean(false);
    }

    abstract equals(other: any): boolean;
    abstract hashCode(): number;
}