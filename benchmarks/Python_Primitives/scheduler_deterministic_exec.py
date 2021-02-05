from btypes.BBoolean import BBoolean
from btypes.BInteger import BInteger
from btypes.BObject import BObject
from scheduler_deterministic import *


class scheduler_deterministic_exec:


    def __init__(self):
        self._scheduler_deterministic = scheduler_deterministic()

        self.counter = BInteger(0)

    def simulate(self):
        while((self.counter.less(BInteger(300000))).booleanValue()):
            self._scheduler_deterministic.new(PID.process1)
            self._scheduler_deterministic.new(PID.process2)
            self._scheduler_deterministic.new(PID.process3)
            self._scheduler_deterministic._del(PID.process1)
            self._scheduler_deterministic.new(PID.process1)
            self._scheduler_deterministic._del(PID.process2)
            self._scheduler_deterministic._del(PID.process1)
            self._scheduler_deterministic._del(PID.process3)
            self._scheduler_deterministic.new(PID.process1)
            self._scheduler_deterministic.new(PID.process2)
            self._scheduler_deterministic._del(PID.process1)
            self._scheduler_deterministic.ready(PID.process2)
            self._scheduler_deterministic.new(PID.process1)
            self._scheduler_deterministic.new(PID.process3)
            self._scheduler_deterministic._del(PID.process1)
            self._scheduler_deterministic.ready(PID.process3)
            self._scheduler_deterministic.new(PID.process1)
            self._scheduler_deterministic.ready(PID.process1)
            self._scheduler_deterministic.swap(PID.process1)
            self._scheduler_deterministic._del(PID.process2)
            self._scheduler_deterministic.swap(PID.process3)
            self._scheduler_deterministic.new(PID.process2)
            self._scheduler_deterministic._del(PID.process1)
            self._scheduler_deterministic._del(PID.process2)
            self._scheduler_deterministic.swap(PID.process1)
            self._scheduler_deterministic.new(PID.process1)
            self._scheduler_deterministic.new(PID.process2)
            self._scheduler_deterministic._del(PID.process1)
            self._scheduler_deterministic._del(PID.process3)
            self._scheduler_deterministic.new(PID.process1)
            self._scheduler_deterministic._del(PID.process2)
            self._scheduler_deterministic._del(PID.process1)
            self.counter = self.counter.plus(BInteger(1))


if __name__ == '__main__':
    exec = scheduler_deterministic_exec()
    exec.simulate()
