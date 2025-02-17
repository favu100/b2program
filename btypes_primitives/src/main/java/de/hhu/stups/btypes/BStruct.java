package de.hhu.stups.btypes;

public abstract class BStruct implements BObject {

	protected BStruct() {
	}

	public BBoolean isRecord() {
		return BBoolean.TRUE;
	}

	public BBoolean isNotRecord() {
		return BBoolean.FALSE;
	}
}
