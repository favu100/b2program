import {BSet} from "./BSet.js";
import {BBoolean} from "./BBoolean.js";

export class BUtils {
    static readonly BOOL: BSet<BBoolean>  = new BSet<BBoolean>(new BBoolean(true), new BBoolean(false));
}
