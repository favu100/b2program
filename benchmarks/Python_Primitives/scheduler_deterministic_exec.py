from btypes.BBoolean import BBoolean
from btypes.BInteger import BInteger
from btypes.BObject import BObject
from scheduler_deterministic import scheduler_deterministic



class scheduler_deterministic_exec:




    def __init__(self):
        self._scheduler_deterministic = scheduler_deterministic()

        self.counter = BInteger(0)

    def simulate(self):
        while((self.counter.less(BInteger(200000))).booleanValue()):
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process3)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process3)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.ready(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process3)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.ready(scheduler_deterministic.PID.process3)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.ready(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.swap(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic.swap(scheduler_deterministic.PID.process3)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic.swap(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process3)
            self._scheduler_deterministic.new(scheduler_deterministic.PID.process1)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process2)
            self._scheduler_deterministic._del(scheduler_deterministic.PID.process1)
            self.counter = self.counter.plus(BInteger(1))





