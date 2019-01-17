from BInteger import *
from BBoolean import *

class BSet:

    def __init__(self, set):
        self.__set = set

    def union(self, set):
        return BSet(self.__set | set.__set)

    def intersection(self, set):
        return BSet(self.__set & set.__set)

    def complement(self, set):
        return BSet(self.__set - set.__set)

    def card(self):
        return BInteger(self.__set.length)

    def elementOf(self, obj):
        return BBoolean(self.__set.contains(obj))

    @staticmethod
    def range(a, b):
        r = list(map(BInteger, range(a.intValue(), b.intValue() + 1)))
        return BSet(s(*r))