package de.hhu.stups.btypes;

public abstract class BFreetype implements BObject {

    public BBoolean isFreetype() {
        return new BBoolean(true);
    }

    public BBoolean isNotFreetype() {
        return new BBoolean(false);
    }
}
