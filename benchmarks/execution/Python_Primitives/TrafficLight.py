from btypes.BBoolean import BBoolean
from btypes.BSet import BSet
from btypes.BObject import BObject


from enum import Enum, auto
class colors(BObject, Enum):
    red = auto()
    redyellow = auto()
    yellow = auto()
    green = auto()


    def equal(self, o):
        return BBoolean(self == o)

    def unequal(o):
        return BBoolean(self != o)

    def __str__(self):
                if self == colors.red:
                    return "red"
                if self == colors.redyellow:
                    return "redyellow"
                if self == colors.yellow:
                    return "yellow"
                if self == colors.green:
                    return "green"


class TrafficLight:



    _colors = BSet(colors.red, colors.redyellow, colors.yellow, colors.green)

    def __init__(self):
        self.tl_cars = colors.red
        self.tl_peds = colors.red

    def cars_ry(self):
        if((BBoolean(self.tl_cars.equal(colors.red).booleanValue() and self.tl_peds.equal(colors.red).booleanValue())).booleanValue()):
            self.tl_cars = colors.redyellow


    def cars_y(self):
        if((BBoolean(self.tl_cars.equal(colors.green).booleanValue() and self.tl_peds.equal(colors.red).booleanValue())).booleanValue()):
            self.tl_cars = colors.yellow


    def cars_g(self):
        if((BBoolean(self.tl_cars.equal(colors.redyellow).booleanValue() and self.tl_peds.equal(colors.red).booleanValue())).booleanValue()):
            self.tl_cars = colors.green


    def cars_r(self):
        if((BBoolean(self.tl_cars.equal(colors.yellow).booleanValue() and self.tl_peds.equal(colors.red).booleanValue())).booleanValue()):
            self.tl_cars = colors.red


    def peds_r(self):
        if((BBoolean(self.tl_peds.equal(colors.green).booleanValue() and self.tl_cars.equal(colors.red).booleanValue())).booleanValue()):
            self.tl_peds = colors.red


    def peds_g(self):
        if((BBoolean(self.tl_peds.equal(colors.red).booleanValue() and self.tl_cars.equal(colors.red).booleanValue())).booleanValue()):
            self.tl_peds = colors.green


    def _get_tl_cars(self):
        return self.tl_cars

    def _get_tl_peds(self):
        return self.tl_peds


