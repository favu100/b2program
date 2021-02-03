from btypes.BObject import *
from btypes.BBoolean import *


class BTuple(BObject):

    def __init__(self, first, second):
        if first is None or second is None:
            raise ValueError()
        self.first = first
        self.second = second

    def __eq__(self, other):
        return self.equals(other)

    def equals(self, other) -> 'bool':
        if self is other:
            return True
        if other is None or type(self) != type(other):
            return False

        b_objects = other
        # elements is never None
        return b_objects.projection1().__eq__(self.first) and b_objects.projection2().__eq__(self.second)

    def __hash__(self):
        return hash(hash(self.first) + hash(self.second))

    def projection1(self):
        return self.first

    def projection2(self):
        return self.second

    def __str__(self):
        return "(" + str(self.projection1()) + " |-> " + str(self.projection2()) + ')'

    def equal(self, other: 'BTuple') -> 'BBoolean':
        return BBoolean(self.equals(other))

    def unequal(self, other: 'BTuple') -> 'BBoolean':
        return BBoolean(not self.equals(other))
