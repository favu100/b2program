import { BBoolean } from "https://favu100.github.io/b2program/LandingGear/GearsDoors/btypes/BBoolean.js";
export class BStruct {
    isRecord() {
        return new BBoolean(true);
    }
    isNotRecord() {
        return new BBoolean(false);
    }
}
