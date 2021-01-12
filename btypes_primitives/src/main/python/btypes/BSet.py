from btypes.BInteger import *
from btypes.BBoolean import *
from btypes.BString import *
from btypes.BStruct import *
import random
from itertools import chain, combinations

class BSet:

    def __init__(self, *args):
        if len(args) == 1 and type(args[0]) is frozenset:
            self.__set = args[0]
        else:
            self.__set = frozenset(args)

    def __str__(self) ->'str':
        return '{' + ', '.join(self.__set) + '}'

    def __eq__(self, other):
        if self == other:
            return True
        if other is None or type(self) != type(other):
            return False
        if not self.__set == other.__set:
            return False
        return True

    def __ne__(self, other):
        return not self.__eq__(other)

    def union(self, set: 'BSet') -> 'BSet':
        return BSet(self.__set.union(set.getSet()))

    def intersect(self, set: 'BSet') -> 'BSet':
        return BSet(self.__set.intersection(set.__set))

    def difference(self, other: 'BSet') -> 'BSet':
        return BSet(self.__set.difference(other.__set))

    def complement(self, set: 'BSet') -> 'BSet':
        return BSet(self.__set.difference(set.__set))

    def card(self) -> 'BInteger':
        return BInteger(len(self.__set))

    def size(self) -> 'BInteger':
        return BInteger(len(self.__set))

    def elementOf(self, obj) -> 'BBoolean':
        return BBoolean(obj in self.__set)

    def notElementOf(self, obj) -> 'BBoolean':
        return BBoolean(obj not in self.__set)

    def subset(self,other: 'BSet') -> 'BBoolean':
        return BBoolean(self.__set.issubset(other.__set))

    def notSubset(self,other: 'BSet') -> 'BBoolean':
        return BBoolean(not self.__set.issubset(other.__set))

    def strictSubset(self,other: 'BSet') -> 'BBoolean':
        return BBoolean(other.size() != self.size() and self.__set.issubset(other.__set))

    def strictNotSubset(self,other: 'BSet') -> 'BBoolean':
        return BBoolean(other.size() == self.size() and not self.__set.issubset(other.__set))

    def contains(self, other):
        return o in self.__set

    def containsAll(self, other):
        for o in other:
            if not o in self.__set:
                return False
        return True

    def isEmpty(self) -> 'int':
        return len(self.__set) == 0

    def equal(self, other) -> 'bool':
        return self.__eq__(other)

    def unequal(self, other) -> 'bool':
        return self.__ne__(other)

    def nondeterminism(self):
        return random.choice(self.__set)

    def min(self):
        return min(self.__set)

    def max(self):
        return max(self.__set)

    def pow(self) -> 'BSet':
        s = list(self.__set)
        return BSet(chain.from_iterable(combinations(s, r) for r in range(len(s)+1)))

    def pow1(self) -> 'BSet':
        return self.pow().difference(BSet())

    def fin(self) -> 'BSet':
        return self.pow()

    def fin1(self) -> 'BSet':
        return self.pow1()

    def subsetOfInteger(self) -> 'BBoolean':
        for element in self.__set:
            if not isinstance(element, BInteger):
                return False
        return True

    def strictSubsetOfInteger(self) -> 'BBoolean':
        return self.subsetOfInteger()

    def notSubsetOfInteger(self) -> 'BBoolean':
        return self.subsetOfInteger()._not()

    def notStrictSubsetOfInteger(self) -> 'BBoolean':
        return self.strictSubsetOfInteger()._not()

    def subsetOfNatural(self) -> 'BBoolean':
        for element in self.__set:
            if not (isinstance(element, BInteger) and element.isNatural().booleanValue()):
                return False
        return True

    def strictSubsetOfNatural(self) -> 'BBoolean':
        return self.subsetOfInteger()

    def notSubsetOfNatural(self) -> 'BBoolean':
        return self.subsetOfInteger()._not()

    def notStrictSubsetOfNatural(self) -> 'BBoolean':
        return self.strictSubsetOfInteger()._not()

    def subsetOfNatural1(self) -> 'BBoolean':
        for element in self.__set:
            if not (isinstance(element, BInteger) and element.isNatural1().booleanValue()):
                return False
        return True

    def strictSubsetOfNatural(self) -> 'BBoolean':
        return self.subsetOfInteger()

    def notSubsetOfNatural(self) -> 'BBoolean':
        return self.subsetOfInteger()._not()

    def notStrictSubsetOfNatural(self) -> 'BBoolean':
        return self.strictSubsetOfInteger()._not()

    def subsetOfString(self) -> 'BBoolean':
        for element in self.__set:
            if not isinstance(element, BString):
                return False
        return True

    def strictSubsetOfString(self) -> 'BBoolean':
        return self.subsetOfInteger()

    def notSubsetOfString(self) -> 'BBoolean':
        return self.subsetOfInteger()._not()

    def notStrictSubsetOfString(self) -> 'BBoolean':
        return self.strictSubsetOfInteger()._not()

    def subsetOfStruct(self) -> 'BBoolean':
        for element in self.__set:
            if not isinstance(element, BStruct):
                return False
        return True

    def strictSubsetOfStruct(self) -> 'BBoolean':
        return self.subsetOfInteger()

    def notSubsetOfStruct(self) -> 'BBoolean':
        return self.subsetOfInteger()._not()

    def notStrictSubsetOfStruct(self) -> 'BBoolean':
        return self.strictSubsetOfInteger()._not()

    def equalInteger(self) -> 'BBoolean':
        return BBoolean(False)

    def unequalInteger(self) -> 'BBoolean':
        return BBoolean(True)

    def equalNatural(self) -> 'BBoolean':
        return BBoolean(False)

    def unequalNatural(self) -> 'BBoolean':
        return BBoolean(True)

    def equalNatural1(self) -> 'BBoolean':
        return BBoolean(False)

    def unequalNatural1(self) -> 'BBoolean':
        return BBoolean(True)

    def equalString(self) -> 'BBoolean':
        return BBoolean(False)

    def unequalString(self) -> 'BBoolean':
        return BBoolean(True)

    def equalStruct(self) -> 'BBoolean':
        return BBoolean(False)

    def unequalStruct(self) -> 'BBoolean':
        return BBoolean(True)

    def getSet(self):
        return self.__set

    @staticmethod
    def interval(a: 'BInteger', b: 'BInteger') -> 'BSet':
        r = list(map(BInteger, range(a.intValue(), b.intValue() + 1)))
        return BSet(*r)



    def hashCode(self):
        return hash(self.__set)