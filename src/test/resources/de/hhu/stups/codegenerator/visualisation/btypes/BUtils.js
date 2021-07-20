"use strict";
import BBoolean from "./BBoolean.js";
import BSet from "./BSet.js"

export default class BUtils {
    static BOOL = new BSet(new BBoolean(true), new BBoolean(false));
}
