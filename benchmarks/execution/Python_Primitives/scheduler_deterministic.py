from btypes.BBoolean import BBoolean
from btypes.BSet import BSet
from btypes.BObject import BObject


from enum import Enum, auto
class PID(BObject, Enum):
    process1 = auto()
    process2 = auto()
    process3 = auto()


    def equal(self, o):
        return BBoolean(self == o)

    def unequal(o):
        return BBoolean(self != o)

    def __str__(self):
                if self == PID.process1:
                    return "process1"
                if self == PID.process2:
                    return "process2"
                if self == PID.process3:
                    return "process3"


class scheduler_deterministic:



    _PID = BSet(PID.process1, PID.process2, PID.process3)

    def __init__(self):
        self.active = BSet()
        self._ready = BSet()
        self.waiting = BSet()

    def new(self, pp):
        if((BBoolean(BBoolean(self._PID.elementOf(pp).booleanValue() and self.active.notElementOf(pp).booleanValue()).booleanValue() and self._ready.union(self.waiting).notElementOf(pp).booleanValue())).booleanValue()):
            self.waiting = self.waiting.union(BSet(pp))


    def _del(self, pp):
        if((self.waiting.elementOf(pp)).booleanValue()):
            self.waiting = self.waiting.difference(BSet(pp))


    def ready(self, rr):
        if((self.waiting.elementOf(rr)).booleanValue()):
            self.waiting = self.waiting.difference(BSet(rr))
            if self.active.equal(BSet()):
                self.active = BSet(rr)
            else:
                self._ready = self._ready.union(BSet(rr))


    def swap(self, pp):
        if self.active.unequal(BSet()):
            self.waiting = self.waiting.union(self.active)
            if self._ready.equal(BSet()):
                self.active = BSet()
            else:
                self.active = BSet(pp)
                self._ready = self._ready.difference(BSet(pp))


    def _get_active(self):
        return self.active

    def _get__ready(self):
        return self._ready

    def _get_waiting(self):
        return self.waiting


