from btypes.BBoolean import BBoolean
from btypes.BInteger import BInteger
from TrafficLight import TrafficLight



class TrafficLightExec:




    def __init__(self):
        self._TrafficLight = TrafficLight()

        self.counter = BInteger(0)

    def simulate(self):
        while((self.counter.less(BInteger(300000000))).booleanValue()):
            self._TrafficLight.cars_ry()
            self._TrafficLight.cars_g()
            self._TrafficLight.cars_y()
            self._TrafficLight.cars_r()
            self._TrafficLight.peds_g()
            self._TrafficLight.peds_r()
            self.counter = self.counter.plus(BInteger(1))


if __name__ == '__main__':
    traffic = TrafficLightExec()
    traffic.simulate()
