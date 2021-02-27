from btypes.BBoolean import *


class BInteger:

    def __init__(self, value):
        self.__value = value

    def __add__(self, other):
        if type(other) == str:
            return str(self) + other
        return BInteger(self.__value + other.__value)

    def __radd__(self, other):
        if type(other) == str:
            return other + str(self)
        return BInteger(self.__value + other.__value)

    def __sub__(self, other: 'BInteger') -> 'BInteger':
        return BInteger(self.__value - other.__value)

    def __mul__(self, other: 'BInteger') -> 'BInteger':
        return BInteger(self.__value * other.__value)

    def __mod__(self, other: 'BInteger') -> 'BInteger':
        return BInteger(self.__value % other.__value)

    def __div__(self, other: 'BInteger') -> 'BInteger':
        return BInteger(self.__value // other.__value)

    def __neg__(self) -> 'BInteger':
        return BInteger(-self.__value)

    def __lt__(self, other: 'BInteger') -> 'bool':
        return self.__value < other.__value

    def __le__(self, other: 'BInteger') -> 'bool':
        return self.__value <= other.__value

    def __eq__(self, other: 'BInteger') -> 'bool':
        if not isinstance(other, BInteger):
            return False
        return self.__value == other.__value

    def __ne__(self, other: 'BInteger') -> 'bool':
        return self.__value != other.__value

    def __gt__(self, other: 'BInteger') -> 'bool':
        return self.__value > other.__value

    def __ge__(self, other: 'BInteger') -> 'bool':
        return self.__value >= other.__value

    def __pow__(self, other: 'BInteger') -> 'BInteger':
        return self.__value ** other.__value

    def __str__(self) -> 'str':
        return str(self.__value)

    def plus(self, other: 'BInteger') -> 'BInteger':
        return self.__add__(other)

    def minus(self, other: 'BInteger') -> 'BInteger':
        return self.__sub__(other)

    def multiply(self, other: 'BInteger') -> 'BInteger':
        return self.__mul__(other)

    def modulo(self, other: 'BInteger') -> 'BInteger':
        return self.__mod__(other)

    def divide(self, other: 'BInteger') -> 'BInteger':
        return self.__div__(other)

    def negative(self) -> 'BInteger':
        return self.__neg__()

    def less(self, other: 'BInteger') -> 'BBoolean':
        return BBoolean(self.__value < other.__value)

    def lessEqual(self, other: 'BInteger') -> 'BBoolean':
        return BBoolean(self.__value <= other.__value)

    def equal(self, other: 'BInteger') -> 'BBoolean':
        return BBoolean(self.__value == other.__value)

    def unequal(self, other: 'BInteger') -> 'BBoolean':
        return BBoolean(self.__value != other.__value)

    def greater(self, other: 'BInteger') -> 'BBoolean':
        return BBoolean(self.__value > other.__value)

    def greaterEqual(self, other: 'BInteger') -> 'BBoolean':
        return BBoolean(self.__value >= other.__value)

    def succ(self) -> 'BInteger':
        return BInteger(self.__value + 1)

    def pred(self) -> 'BInteger':
        return BInteger(self.__value - 1)

    def power(self, other: 'BInteger') -> 'BInteger':
        return self.__pow__(other)

    def positive(self):
        return self

    def intValue(self):
        return self.__value

    def isInteger(self) -> 'BBoolean':
        return BBoolean(true)

    def isNotInteger(self) -> 'BBoolean':
        return BBoolean(false)

    def isNatural(self) -> 'BBoolean':
        return self.greaterEqual(BInteger(0))

    def isNotNatural(self) -> 'BBoolean':
        return self.isNatural()._not()

    def isNatural1(self) -> 'BBoolean':
        return self.greater(BInteger(0))

    def isNotNatural1(self) -> 'BBoolean':
        return self.isNatural1()._not()

    def __hash__(self):
        return hash(31 + self.__value)