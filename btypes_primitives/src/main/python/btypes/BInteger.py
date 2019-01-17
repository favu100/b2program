from BBoolean import *

class BInteger:

    def __init__(self, value):
        self.__value = value

    def plus(self, o):
        return BInteger(self.__value + o.__value)

    def minus(self, o):
        return BInteger(self.__value - o.__value)

    def multiply(self, o):
        return BInteger(self.__value * o.__value)

    def divide(self, o):
        return BInteger(self.__value / o.__value)

    def modulo(self, o):
        return BInteger(self.__value  % o.__value)

    def power(self, o):
        return BInteger(self.__value ^ o.__value)

    def lessEqual(self, o):
        return BBoolean(self.__value <= o.__value)

    def less(self, o):
        return BBoolean(self.__value < o.__value)

    def equal(self, o):
        return BBoolean(self.__value == o.__value)

    def unequal(self, o):
        return BBoolean(self.__value == o.__value)

    def greater(self, o):
        return BBoolean(self.__value > o.__value)

    def greaterEqual(self, o):
        return BBoolean(self.__value >= o.__value)

    def negative(self):
        return BInteger(self.__value)

    def positive(self):
        return self

    def intValue(self):
        return self.__value

    def next(self):
        return BInteger(self.__value + 1)

    def __eq__(self, other):
        return self.__value == other.__value

    def __hash__(self):
        return hash(31 + self.__value)