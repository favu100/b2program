from btypes.BBoolean import BBoolean
from btypes.BInteger import BInteger
from Lift import Lift



class LiftExec:




    def __init__(self):
        self._Lift = Lift()

        self.counter = BInteger(0)

    def simulate(self):
        while((self.counter.less(BInteger(3000))).booleanValue()):
            i = None
            i = BInteger(0)
            while((i.less(BInteger(100))).booleanValue()):
                self._Lift.inc()
                i = i.plus(BInteger(1))

            _i = None
            _i = BInteger(0)
            while((_i.less(BInteger(100))).booleanValue()):
                self._Lift.dec()
                _i = _i.plus(BInteger(1))

            self.counter = self.counter.plus(BInteger(1))



    def getCounter(self):
        out = None
        out = self.counter
        return out



if __name__ == "__main__":
    lift = LiftExec();
    lift.simulate()
    print(lift.getCounter())