import {BObject} from "https://www3.hhu.de/stups/models/visb/btypes/BObject.js";
import {BBoolean} from "https://www3.hhu.de/stups/models/visb/btypes/BBoolean.js";

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