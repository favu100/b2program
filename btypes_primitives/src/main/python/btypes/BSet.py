from btypes.BInteger import *
from btypes.BBoolean import *
from btypes.BString import *
from btypes.BStruct import *


class BSet:

    def __init__(self, *args):
        if len(args) == 1 and type(args[0]) is frozenset:
            self.__set = args[0]
        else:
            self.__set = frozenset(args)

    def __str__(self) -> 'str':
        return '{' + ', '.join([str(x) for x in self.__set]) + '}'

    def __eq__(self, other):
        if self is other:
            return True
        if other is None or type(self) != type(other):
            return False
        if not self.__set == other.__set:
            return False
        return True

    def __ne__(self, other):
        return not self.__eq__(other)

    def __len__(self):
        return len(self.__set)

    def union(self, other=None):
        if other is None:
            if len(self.__set) == 0:
                return BSet()
            elif type(next(iter(self.__set))) == BSet:
                return reduce(lambda a, e: a.union(e), self, BSet())
            elif type(next(iter(self.__set))) == BRelation:
                return reduce(lambda a, e: a.union(e), self, BRelation())

        return BSet(self.__set.union(other.getSet()))

    def intersect(self, other=None):
        if other is None:
            if len(self.__set) == 0:
                return BSet()
            elif type(next(iter(self.__set))) == BSet:
                return reduce(lambda a, e: a.intersect(e), self, BSet())
            elif type(next(iter(self.__set))) == BRelation:
                return reduce(lambda a, e: a.intersect(e), self, BRelation())

        return BSet(self.__set.intersection(other.getSet()))

    def difference(self, other: 'BSet') -> 'BSet':
        return BSet(self.__set.difference(other.__set))

    def complement(self, other: 'BSet') -> 'BSet':
        return BSet(self.__set.difference(other.__set))

    def card(self) -> 'BInteger':
        return BInteger(len(self.__set))

    def size(self) -> 'BInteger':
        return BInteger(len(self.__set))

    def elementOf(self, obj) -> 'BBoolean':
        return BBoolean(obj in self.__set)

    def notElementOf(self, obj) -> 'BBoolean':
        return BBoolean(obj not in self.__set)

    def subset(self, other: 'BSet') -> 'BBoolean':
        return BBoolean(self.__set.issubset(other.__set))

    def notSubset(self, other: 'BSet') -> 'BBoolean':
        return BBoolean(not self.__set.issubset(other.__set))

    def strictSubset(self, other: 'BSet') -> 'BBoolean':
        return BBoolean(other.size() != self.size() and self.__set.issubset(other.__set))

    def strictNotSubset(self, other: 'BSet') -> 'BBoolean':
        return BBoolean(other.size() == self.size() and not self.__set.issubset(other.__set))

    def contains(self, other):
        return other in self.__set

    def containsAll(self, other):
        for o in other:
            if o not in self.__set:
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
        result = BSet()
        start = BSet()
        queue = [start]
        result = result.union(BSet(start))
        while not (len(queue) == 0):
            currentSet = queue.pop()
            for element in self.__set:
                nextSet = currentSet.union(BSet(element))
                previousSize = result.size()
                result = result.union(BSet(nextSet))
                if previousSize < result.size():
                    queue.append(nextSet)

        return result
        # s = list(self.__set)
        # return BSet(frozenset(chain.from_iterable(BSet(combinations(s, r)) for r in range(len(s) + 1))))

    def pow1(self) -> 'BSet':
        return self.pow().difference(BSet(BSet()))

    # Only finite subsets are supported so fin = pow
    def fin(self) -> 'BSet':
        return self.pow()

    def fin1(self) -> 'BSet':
        return self.pow1()

    def subsetOfInteger(self) -> 'bool':
        for element in self.__set:
            if not isinstance(element, BInteger):
                return False
        return True

    def strictSubsetOfInteger(self) -> 'bool':
        return self.subsetOfInteger()

    def notSubsetOfInteger(self) -> 'bool':
        return not self.subsetOfInteger()

    def notStrictSubsetOfInteger(self) -> 'bool':
        return not self.strictSubsetOfInteger()

    def subsetOfNatural(self) -> 'bool':
        for element in self.__set:
            if not (isinstance(element, BInteger) and element.isNatural().booleanValue()):
                return False
        return True

    def strictSubsetOfNatural(self) -> 'bool':
        return self.subsetOfNatural()

    def notSubsetOfNatural(self) -> 'bool':
        return not self.subsetOfNatural()

    def notStrictSubsetOfNatural(self) -> 'bool':
        return not self.strictSubsetOfNatural()

    def subsetOfNatural1(self) -> 'bool':
        for element in self.__set:
            if not (isinstance(element, BInteger) and element.isNatural1().booleanValue()):
                return False
        return True

    def subsetOfString(self) -> 'bool':
        for element in self.__set:
            if not isinstance(element, BString):
                return False
        return True

    def strictSubsetOfString(self) -> 'bool':
        return self.subsetOfString()

    def notSubsetOfString(self) -> 'bool':
        return not self.subsetOfString()

    def notStrictSubsetOfString(self) -> 'bool':
        return not self.strictSubsetOfString()

    def subsetOfStruct(self) -> 'bool':
        for element in self.__set:
            if not isinstance(element, BStruct):
                return False
        return True

    def strictSubsetOfStruct(self) -> 'bool':
        return self.subsetOfStruct()

    def notSubsetOfStruct(self) -> 'bool':
        return not self.subsetOfStruct()

    def notStrictSubsetOfStruct(self) -> 'bool':
        return not self.strictSubsetOfStruct()

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

    def __hash__(self):
        return hash(self.__set)

    def __iter__(self):
        return iter(self.__set)

#Import is at the bottom due to cyclic dependencies
from btypes.BRelation import *
