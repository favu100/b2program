from z3 import Int
from z3 import ArithRef
from z3 import BoolRef
from z3 import And


def greater(self, other):
    return self > other


def less(self, other):
    return self < other


def equal(self, other):
    return self == other


def __and(self, other):
    return And(self, other)


setattr(ArithRef, 'greater', greater)
setattr(ArithRef, 'less', less)
setattr(ArithRef, 'equal', equal)
setattr(BoolRef, '_and', __and)
