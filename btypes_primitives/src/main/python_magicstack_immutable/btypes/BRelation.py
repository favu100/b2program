from btypes.BInteger import *
from btypes.BBoolean import *
from btypes.BInteger import BInteger
from btypes.BTuple import *
from btypes.BSet import *

import immutables
from functools import reduce
import random

from z3 import Solver
from z3 import sat
from z3 import And

class BRelation:

    def __init__(self, *args):
        if len(args) == 0:
            self.map = immutables.Map()
        elif len(args) == 1 and type(args[0]) == immutables.Map:
            self.map = args[0]
        else:
            self.map = immutables.Map()
            for e in args:
                key = e.projection1()
                value = e.projection2()
                _set = self.map.get(key)
                if not _set:
                    _set = immutables.Map()
                _set = _set.set(value, value)
                self.map = self.map.set(key, _set)

    @staticmethod
    def fromSet(_set: 'BSet') -> 'BRelation':
        result_map = immutables.Map()
        for e in _set:
            key = e.projection1()
            value = e.projection2()
            _range = result_map.get(key, None)
            if _range is None:
                _range = immutables.Map({value: value})
                result_map = result_map.set(key, _range)
            else:
                _range = _range.set(value, value)
                result_map = result_map.set(key, _range)

        return BRelation(result_map)

    def __eq__(self, other: 'BRelation') -> 'bool':
        if self is other:
            return True
        if other is None or type(self) != type(other):
            return False
        if not self.map == other.map:
            return False
        return True

    def equals(self, other):
        return self.__eq__(other)

    def __hash__(self):
        return hash(self.map)

    def intersect(self, relation: 'BRelation') -> 'BRelation':
        this_map = self.map
        other_map = relation.map
        # Remove all elements not in other domain
        result_map = reduce(lambda current_map, el: current_map.delete(el) if el not in other_map else current_map,
                            this_map, this_map)
        # Trim range for all elements to match other range
        for obj in result_map:
            this_range = result_map[obj]
            other_range = other_map[obj]
            result_map = result_map.set(obj, reduce(
                lambda current_range, el: current_range.delete(el) if el not in other_range else current_range,
                this_range, this_range))
        return BRelation(result_map)

    def difference(self, relation: 'BRelation') -> 'BRelation':
        this_map = self.map
        other_map = relation.map
        # Remove all elements not in other domain
        result_map = reduce(lambda current_map, el: current_map.delete(el) if el not in other_map else current_map,
                            this_map, this_map)
        # Remove all elements in other range
        for obj in result_map:
            this_range = result_map[obj]
            other_range = other_map[obj]
            result_map = result_map.set(obj, reduce(
                lambda current_range, el: current_range.delete(el) if el in other_range else current_range,
                this_range, this_range))
        return BRelation(result_map)

    def union(self, relation: 'BRelation') -> 'BRelation':
        other_map = relation.map
        result_map = self.map
        for domain_element in other_map:
            this_range_set = self.map.get(domain_element)
            other_range_set = other_map.get(domain_element, None)
            if other_range_set is None:
                continue
            if this_range_set is None:
                this_range_set = immutables.Map()
            for element in other_range_set:
                this_range_set = this_range_set.set(element, element)
            result_map = result_map.set(domain_element, this_range_set)

        return BRelation(result_map)

    def size(self) -> 'int':
        size = 0
        this_map = self.map

        for domain_element in this_map:
            size += len(this_map[domain_element])

        return size

    def card(self) -> 'BInteger':
        return BInteger(self.size())

    def _size(self) -> 'BInteger':
        return BInteger(self.size())

    def equal(self, other: 'BRelation') -> 'BBoolean':
        return BBoolean(self.equals(other))

    def unequal(self, other: 'BRelation') -> 'BBoolean':
        return BBoolean(not self.equals(other))

    def elementOf(self, obj: 'BTuple') -> 'BBoolean':
        prj1 = obj.projection1()
        prj2 = obj.projection2()

        domain = self.map

        if prj1 not in domain:
            return BBoolean(False)

        return BBoolean(prj2 in domain[prj1])

    def notElementOf(self, obj: 'BTuple') -> 'BBoolean':
        prj1 = obj.projection1()
        prj2 = obj.projection2()

        domain = self.map

        if prj1 not in domain:
            return BBoolean(True)

        return BBoolean(prj2 not in domain[prj1])

    def relationImage(self, domain: 'BSet') -> 'BSet':
        result_set = immutables.Map()
        this_map = self.map
        for domain_element in domain:
            this_range_set = this_map.get(domain_element)
            if this_range_set is None:
                continue
            for element in this_range_set:
                result_set = result_set.set(element, element)
        return BSet(result_set)

    def functionCall(self, arg):
        _range = self.map.get(arg)
        if _range is None:
            raise Exception("Argument is not in the domain of this relation")

        for element in _range:
            return element
        raise Exception("Argument is not in the domain of this relation")

    def pow(self) -> 'BSet':
        this_map = self.map

        start = BRelation()
        queue = [start]
        result = BSet(start)
        while not len(queue) == 0:
            current_set = queue.pop(0)

            for domain_element in this_map:
                _range = this_map[domain_element]
                for range_element in _range:
                    next_relation = current_set.union(BRelation.fromSet(BSet(BTuple(domain_element, range_element))))
                    previous_size = result.size()
                    result = result.union(BSet(next_relation))
                    if previous_size < result.size():
                        queue.append(next_relation)

        return result

    def pow1(self) -> 'BSet':
        return self.pow().difference(BSet(BRelation()))

    def fin(self) -> 'BSet':
        return self.pow()

    def fin1(self) -> 'BSet':
        return self.pow1()

    def domain(self) -> 'BSet':
        this_map = self.map
        result_map = this_map
        for domain_element in this_map:
            _range = this_map[domain_element]
            if len(_range) == 0:
                result_map = result_map.delete(domain_element)
        return BSet(result_map)

    def _range(self) -> 'BSet':
        _range = reduce(lambda a, b: a.update(b), self.map.values(), immutables.Map())
        return BSet(_range)

    def inverse(self) -> 'BRelation':
        this_map = self.map
        keys = this_map.keys()

        result_map = immutables.Map()
        for e1 in keys:
            domain_element = e1
            _range = this_map[domain_element]
            for e2 in _range:
                range_element = e2
                current_range = result_map.get(range_element)
                if current_range is None:
                    current_range = immutables.Map()
                current_range = current_range.set(domain_element, domain_element)
                result_map = result_map.set(range_element, current_range)
        return BRelation(result_map)

    def domainRestriction(self, arg: 'BSet') -> 'BRelation':
        result_map = self.map
        for obj in result_map:
            if not obj in arg:
                result_map = result_map.delete(obj)
        return BRelation(result_map)

    def domainSubstraction(self, arg: 'BSet') -> 'BRelation':
        result_map = self.map
        for obj in arg:
            if obj in result_map:
                result_map = result_map.delete(obj)
        return BRelation(result_map)

    def rangeRestriction(self, arg: 'BSet') -> 'BRelation':
        other_set = arg.getSet()
        this_domain = self.map

        result_map = self.map
        for domain_element in this_domain:
            this_range_set = self.map[domain_element]

            # Intersection of sets
            this_range_set = reduce(lambda current_set, el: current_set.delete(el) if el not in other_set else current_set, this_range_set, this_range_set)

            result_map = result_map.set(domain_element, this_range_set)
        return BRelation(result_map)

    def rangeSubstraction(self, arg: 'BSet') -> 'BRelation':
        other_set = arg.getSet()
        this_domain = self.map

        result_map = self.map
        for domain_element in this_domain:
            this_range_set = self.map[domain_element]

            # Difference of sets
            this_range_set = reduce(lambda current_set, el: current_set.delete(el) if el in this_range_set else current_set,
                                    other_set, this_range_set)
            result_map = result_map.set(domain_element, this_range_set)
        return BRelation(result_map)

    def override(self, arg: 'BRelation') -> 'BRelation':
        other_map = arg.map
        result_map = self.map

        for domain_element in other_map:
            _range = other_map[domain_element]
            result_map = result_map.set(domain_element, _range)

        return BRelation(result_map)

    def first(self):
        return self.functionCall(BInteger(1))

    def last(self):
        return self.functionCall(self.card())

    def reverse(self) -> 'BRelation':
        size = self.card()
        result_map = immutables.Map()
        for i in map(BInteger, range(1, size.intValue() + 1)):
            range_element = self.functionCall(size.minus(i).succ())
            result_map = result_map.set(i, immutables.Map({range_element: range_element}))
        return BRelation(result_map)

    def front(self) -> 'BRelation':
        return self.domainSubstraction(BSet(self.card()))

    def tail(self) -> 'BRelation':
        size = self._size().intValue()
        result_map = immutables.Map()
        for i in map(BInteger, range(2, size + 1)):
            range_element = self.functionCall(i)
            result_map = result_map.set(i.pred(), immutables.Map({range_element: range_element}))
        return BRelation(result_map)

    def take(self, n: 'BInteger') -> 'BRelation':
        size = self._size()
        if n.greaterEqual(size).booleanValue():
            return BRelation(self.map)
        result_map = self.map
        # Remove sets with index greater than n
        i: BInteger
        for i in map(BInteger, range(n.intValue() + 1, size.intValue() + 1)):
            result_map = result_map.delete(i)
        return BRelation(result_map)

    def drop(self, n: 'BInteger') -> 'BRelation':
        size = self._size().intValue()
        this_map = self.map
        result_map = immutables.Map()
        for i in map(BInteger, range(n.intValue() + 1, size + 1)):
            current_set = this_map[i]
            result_map = result_map.set(i.minus(n), current_set)
        return BRelation(result_map)

    def concat(self, arg: 'BRelation') -> 'BRelation':
        result_map = self.map
        other_map = arg.map
        size = self.card()
        for i in map(BInteger, range(1, arg._size().intValue() + 1)):
            result_map = result_map.set(size.plus(i), other_map[i])
        return BRelation(result_map)

    def conc(self) -> 'BRelation':
        result = BRelation()
        size = self.card().intValue()
        for i in map(BInteger, range(1, size + 1)):
            result = result.concat(self.functionCall(i))
        return result

    def append(self, arg) -> 'BRelation':
        result_map = self.map
        result_map = result_map.set(self.card().succ(), immutables.Map({arg: arg}))
        return BRelation(result_map)

    def prepend(self, arg) -> 'BRelation':
        result_map = immutables.Map()
        this_map = self.map
        size = self._size().intValue()
        for i in map(BInteger, range(1, size + 1)):
            result_map = result_map.set(i.succ(), this_map.get(i))
        result_map = result_map.set(BInteger(1), immutables.Map({arg: arg}))
        return BRelation(result_map)

    def directProduct(self, arg: 'BRelation') -> 'BRelation':
        this_map = self.map
        other_map = arg.map

        result_map = immutables.Map()
        for domain_element in this_map:
            other_range = other_map.get(domain_element)
            if other_range is None:
                continue
            this_range = this_map.get(domain_element)
            result_range = immutables.Map()
            for lhs in this_range:
                for rhs in other_range:
                    _tuple = BTuple(lhs, rhs)
                    result_range = result_range.set(_tuple, _tuple)
            result_map = result_map.set(domain_element, result_range)
        return BRelation(result_map)

    def parallelProduct(self, arg: 'BRelation') -> 'BRelation':
        this_map = self.map
        other_map = arg.map
        result_map = immutables.Map()

        for domain_elementThis in this_map:
            for domaineElementOther in other_map:

                this_range = this_map[domain_elementThis]
                other_range = other_map[domaineElementOther]
                result_range = immutables.Map()

                for lhs in this_range:
                    for rhs in other_range:
                        pair_tuple = BTuple(lhs, rhs)
                        result_range = result_range.set(pair_tuple, pair_tuple)
                _tuple = BTuple(domain_elementThis, domaineElementOther)
                result_map = result_map.set(_tuple, result_range)
        return BRelation(result_map)

    def composition(self, arg: 'BRelation') -> 'BRelation':
        this_map = self.map
        other_map = arg.map

        result_map = immutables.Map()

        for domain_element in this_map:
            _range = this_map[domain_element]

            _set = immutables.Map()
            for range_element in _range:
                union_element = other_map.get(range_element)
                if union_element is None:
                    continue
                for element in union_element:
                    _set = _set.set(element, element)
            result_map = result_map.set(domain_element, _set)
        return BRelation(result_map)

    def iterate(self, n: 'BInteger') -> 'BRelation':
        this_relation = self
        result = self.identity(self.domain())
        for _ in range(1, n.intValue() + 1):
            result = result.union(result.composition(this_relation))
        return result

    def closure(self) -> 'BRelation':
        result = self.identity(self.domain())
        next_result = result.composition(self)
        while True:
            last_result = result
            result = result.union(next_result)
            next_result = result.composition(self)
            if result.equal(last_result).booleanValue():
                break
        return result

    def closure1(self) -> 'BRelation':
        result = self
        next_result = result.composition(self)
        while True:
            last_result = result
            result = result.union(next_result)
            next_result = result.composition(self)
            if result.equal(last_result).booleanValue():
                break
        return result

    @staticmethod
    def projection1(arg1: 'BSet', arg2: 'BSet') -> 'BRelation':
        arg_set_1 = arg1.getSet()
        arg_set_2 = arg2.getSet()

        result_map = immutables.Map()
        for element1 in arg_set_1:
            element1_tuple = immutables.Map({element1: element1})
            for element2 in arg_set_2:
                _tuple = BTuple(element1, element2)
                result_map = result_map.set(_tuple, element1_tuple)
        return BRelation(result_map)

    @staticmethod
    def projection2(arg1: 'BSet', arg2: 'BSet') -> 'BRelation':
        arg_set_1 = arg1.getSet()
        arg_set_2 = arg2.getSet()

        result_map = immutables.Map()
        for element2 in arg_set_2:
            element2_tuple = immutables.Map({element2: element2})
            for element1 in arg_set_1:
                _tuple = BTuple(element1, element2)
                result_map = result_map.set(_tuple, element2_tuple)
        return BRelation(result_map)

    def fnc(self) -> 'BRelation':
        this_map = self.map
        domain = self.domain().getSet()

        result_map = immutables.Map()
        for domain_element in domain:
            _range = this_map[domain_element]
            range_set = BSet(_range)
            result_map = result_map.set(domain_element, immutables.Map({range_set: range_set}))
        return BRelation(result_map)

    def rel(self) -> 'BRelation':
        domain = self.domain()

        result_map = immutables.Map()
        for domain_element in domain:
            _range = self.functionCall(domain_element)
            range_set = _range.getSet()
            result_map = result_map.set(domain_element, range_set)
        return BRelation(result_map)

    @staticmethod
    def identity(arg: 'BSet') -> 'BRelation':
        result_map = immutables.Map()
        for e in arg:
            result_map = result_map.set(e, immutables.Map({e: e}))
        return BRelation(result_map)

    @staticmethod
    def cartesianProduct(arg1: 'BSet', arg2: 'BSet') -> 'BRelation':
        result_map = immutables.Map()
        for e1 in arg1:
            result_map = result_map.set(e1, arg2.getSet())
        return BRelation(result_map)

    def nondeterminism(self) -> 'BTuple':
        index = random.choice(range(len(self.map)))
        i = 0
        domain_element = None
        for obj in self.map:
            if i == index:
                domain_element = obj
                break
            i = i + 1

        _range = self.map[domain_element]
        index = random.choice(range(len(_range)))
        i = 0
        for obj in _range:
            if i == index:
                return BTuple(domain_element, obj)
            i = i + 1
        return None

    def isTotal(self, domain: 'BSet'):
        return self.domain().equal(domain)

    def isTotalInteger(self) -> 'BBoolean':
        return BBoolean(False)

    def isTotalNatural(self) -> 'BBoolean':
        return BBoolean(False)

    def isTotalNatural1(self) -> 'BBoolean':
        return BBoolean(False)

    def isTotalString(self) -> 'BBoolean':
        return BBoolean(False)

    def isTotalStruct(self) -> 'BBoolean':
        return BBoolean(False)

    def isPartial(self, domain: 'BSet'):
        return self.domain().strictSubset(domain)

    def isPartialInteger(self):
        for e in self.domain():
            if (isinstance(e, BInteger)):
                return BBoolean(True)
            else:
                return BBoolean(False)
        return BBoolean(True)

    def isPartialNatural(self):
        for e in self.domain():
            if (isinstance(e, BInteger) and not e.isNatural().booleanValue()):
                return BBoolean(False)
        return BBoolean(True)

    def isPartialNatural1(self):
        for e in self.domain():
            if isinstance(e, BInteger) and not e.isNatural1().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def isPartialString(self):
        for e in self.domain():
            if isinstance(e, BString) and not e.isString().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def isPartialStruct(self):
        for e in self.domain():
            if isinstance(e, BStruct) and not e.isRecord().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkDomain(self, domain: 'BSet'):
        return self.domain().subset(domain)

    def checkDomainInteger(self):
        for e in self.domain():
            if isinstance(e, BInteger):
                return BBoolean(True)
            else:
                return BBoolean(False)
        return BBoolean(True)

    def checkDomainNatural(self):
        for e in self.domain():
            if isinstance(e, BInteger) and not e.isNatural().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkDomainNatural1(self):
        for e in self.domain():
            if isinstance(e, BInteger) and not e.isNatural1().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkDomainString(self):
        for e in self.domain():
            if isinstance(e, BString) and not e.isString().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkDomainStruct(self):
        for e in self.domain():
            if isinstance(e, BStruct) and not e.isRecord().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkRange(self, _range: 'BSet'):
        return self._range().subset(_range)

    def checkRangeInteger(self):
        for e in self._range():
            if isinstance(e, BInteger):
                return BBoolean(True)
            else:
                return BBoolean(False)
        return BBoolean(True)

    def checkRangeNatural(self):
        for e in self._range():
            if isinstance(e, BInteger) and not e.isNatural().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkRangeNatural1(self):
        for e in self._range():
            if isinstance(e, BInteger) and not e.isNatural1().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkRangeString(self):
        for e in self._range():
            if isinstance(e, BString) and not e.isString().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def checkRangeStruct(self) -> 'BBoolean':
        for e in self._range():
            if isinstance(e, BStruct) and not e.isRecord().booleanValue():
                return BBoolean(False)
        return BBoolean(True)

    def isRelation(self) -> 'BBoolean':
        return BBoolean(True)

    def isFunction(self) -> 'BBoolean':
        for element in self.domain():
            _range = self.map[element]
            if _range.size() > 1:
                return BBoolean(False)
        return BBoolean(True)

    def isSurjection(self, _range: 'BSet'):
        return self._range().equal(_range)

    def isSurjectionInteger(self) -> 'BBoolean':
        return BBoolean(False)

    def isSurjectionNatural(self) -> 'BBoolean':
        return BBoolean(False)

    def isSurjectionNatural1(self) -> 'BBoolean':
        return BBoolean(False)

    def isSurjectionString(self) -> 'BBoolean':
        return BBoolean(False)

    def isSurjectionStruct(self) -> 'BBoolean':
        return BBoolean(False)

    def isInjection(self) -> 'BBoolean':
        visited = immutables.Map()
        for element in self.domain():
            _range = self.map[element]
            for e in _range:
                range_element = e
                if range_element in visited:
                    return BBoolean(False)
                visited = visited.set(range_element, range_element)
        return BBoolean(True)

    def isBijection(self, _range: 'BSet'):
        return self.isSurjection(_range) and self.isInjection()

    def isBijectionInteger(self) -> 'BBoolean':
        return BBoolean(False)

    def isBijectionNatural(self) -> 'BBoolean':
        return BBoolean(False)

    def isBijectionNatural1(self) -> 'BBoolean':
        return BBoolean(False)

    def isBijectionString(self) -> 'BBoolean':
        return BBoolean(False)

    def isBijectionStruct(self) -> 'BBoolean':
        return BBoolean(False)

    def __str__(self) -> 'str':

        this_map = self.map

        size = self.size()
        i = 0

        sb = "{"
        for domain_element in this_map:
            _range = this_map[domain_element]
            for range_element in _range:
                sb += "("
                sb += str(domain_element)
                sb += " |-> "
                sb += str(range_element)
                sb += ")"
                if i + 1 < size:
                    sb += ", "
                i = i + 1
        sb += "}"
        return sb

    @staticmethod
    def fromSolver(solver: 'Solver', listOfVariables) -> 'BRelation':
        currentSet = []

        while solver.check() == sat:
            currentTuple = reduce(lambda a, b:  BTuple(solver.model()[a], solver.model()[b]), listOfVariables)
            currentSet.append(currentTuple)
            firstCondition = Or(listOfVariables[0] != solver.model()[listOfVariables[0]],
                                 listOfVariables[1] != solver.model()[listOfVariables[1]])
            solver.add(reduce(lambda a, b:  Or(a, b != solver.model()[b]), listOfVariables[2:], firstCondition))

        return BRelation(*currentSet)
