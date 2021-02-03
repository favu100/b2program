from btypes.BBoolean import *

class BStruct:

    def isRecord(self):
        return BBoolean(True)

    def isNotRecord(self):
        return BBoolean(False)

