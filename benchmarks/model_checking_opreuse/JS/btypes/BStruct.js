import { BBoolean } from "./BBoolean.js";
export class BStruct {
    isRecord() {
        return new BBoolean(true);
    }
    isNotRecord() {
        return new BBoolean(false);
    }
}
