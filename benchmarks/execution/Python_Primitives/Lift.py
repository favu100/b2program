from btypes.BInteger import BInteger



class Lift:




    def __init__(self):
        self.floor = BInteger(0)

    def inc(self):
        self.floor = self.floor.plus(BInteger(1))


    def dec(self):
        self.floor = self.floor.minus(BInteger(1))


    def _get_floor(self):
        return self.floor


