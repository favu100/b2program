from btypes.BInteger import BInteger
from sort_m2_data1000 import sort_m2_data1000


class sort_m2_data1000_exec():

    def __init__(self):
        self._sort_m2_data1000 = sort_m2_data1000()
        self.counter = BInteger(0)
        self.sorted = BInteger(0)

    def simulate(self):
        while (self.sorted.less(BInteger(500))).booleanValue():
            self.counter = BInteger(0)
            while (self.counter.less(BInteger(999).minus(BInteger(2).multiply(self.sorted)))).booleanValue():
                self._sort_m2_data1000.prog2()
                self.counter = self.counter.plus(BInteger(1))
            self.counter = BInteger(0)
            while (self.counter.less(self.sorted)).booleanValue():
                self._sort_m2_data1000.prog1()
                self.counter = self.counter.plus(BInteger(1))
            self._sort_m2_data1000.progress()
            self.sorted = self.sorted.plus(BInteger(1))
        while (self.sorted.less(BInteger(999))).booleanValue():
            self.counter = BInteger(0)
            while (self.counter.less(BInteger(999).minus(self.sorted))).booleanValue():
                self._sort_m2_data1000.prog1()
                self.counter = self.counter.plus(BInteger(1))
            self._sort_m2_data1000.progress()
            self.sorted = self.sorted.plus(BInteger(1))
        self._sort_m2_data1000.final_evt()

if __name__ == '__main__':
    execute = sort_m2_data1000_exec()
    execute.simulate()
