"use strict";
import BBoolean from "./BBoolean.js";
export default class BStruct {
    isRecord() {
        return new BBoolean(true);
    }
    isNotRecord() {
        return new BBoolean(false);
    }
}
