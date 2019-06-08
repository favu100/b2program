package de.hhu.stups.btypes;

public class BStruct implements BObject {

    public BBoolean isRecord() {
        return new BBoolean(true);
    }

    public BBoolean isNotRecord() {
        return new BBoolean(false);
    }
}
