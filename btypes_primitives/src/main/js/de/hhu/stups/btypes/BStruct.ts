import {BObject} from "./BObject";
import {BBoolean} from "./BBoolean";

export class BStruct implements BObject {

    isRecord(): BBoolean {
        return new BBoolean(true);
    }

    isNotRecord(): BBoolean {
        return new BBoolean(false);
    }
}
