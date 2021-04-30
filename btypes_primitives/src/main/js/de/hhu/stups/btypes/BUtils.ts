import {BSet} from "./BSet";
import {BBoolean} from "./BBoolean";

export class BUtils {
    static readonly BOOL: BSet<BBoolean>  = new BSet<BBoolean>(new BBoolean(true), new BBoolean(false));
}
