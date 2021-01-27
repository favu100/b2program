from btypes.BInteger import *
from btypes.BBoolean import *
from btypes.BTuple import *
from btypes.BSet import *
from btypes.BStruct import *

from copy import deepcopy
from functools import reduce
import random


class BRelation:

	def __init__(self, *args):
		if len(args) == 0:
			self.map = dict()
		elif len(args) == 1 and type(args[0]) == dict:
			self.map = args[0]
		else:
			self.map = {}
			for e in args:
				key = e.projection1()
				value = e.projection2()
				_set = self.map.get(key)
				if not _set:
					_set = frozenset()
				_set = _set.union({value})
				self.map[key] = _set

	@staticmethod
	def fromSet(_set: 'BSet') -> 'BRelation':
		result_map = {}
		for e in _set:
			key = e.projection1()
			value = e.projection2()
			_range = result_map.get(key, None)
			if _range is None:
				_range = {value}
				result_map[key] = _range
			else:
				_range = _range.union({value})
				result_map[key] = _range

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
		return hash(frozenset(self.map))

	def intersect(self, relation: 'BRelation') -> 'BRelation':
		other_map = relation.map
		other_domain = set(relation.map.keys())
		this_domain = set(self.map.keys())
		intersection_domain = this_domain.intersection(other_domain)
		difference_domain = this_domain.difference(other_domain)

		result_map = self.map
		for obj in intersection_domain:
			domain_element = obj
			this_range_set = self.map[domain_element]
			other_range_set = other_map[domain_element]
			result_map[domain_element] = this_range_set.union(other_range_set)

		for obj in difference_domain:
			domain_element = obj
			result_map.pop(domain_element, None)

		return BRelation(result_map)

	def difference(self, relation: 'BRelation') -> 'BRelation':
		other_map = relation.map
		other_domain = set(other_map.keys())
		this_domain = set(self.map.keys())
		difference_domain = this_domain.difference(other_domain)
		rest_domain = this_domain.difference(difference_domain)

		result_map = self.map
		for obj in difference_domain:
			domain_element = obj
			this_range_set = self.map[domain_element]
			other_range_set = other_map[domain_element]
			result_map[domain_element] = this_range_set.difference(other_range_set)

		for obj in rest_domain:
			domain_element = obj
			result_map.pop(domain_element, None)
			
		return BRelation(result_map)

	def union(self, relation: 'BRelation') -> 'BRelation':
		other_map = relation.map
		other_domain = other_map.keys()

		result_map = deepcopy(self.map)
		for obj in other_domain:
			domain_element = obj
			this_range_set = self.map.get(domain_element)
			other_range_set = relation.map.get(domain_element, None)
			if this_range_set is None:
				this_range_set = set()
			result_map[domain_element] = this_range_set.union(other_range_set)
			
		return BRelation(result_map)

	def size(self) -> 'int':
		size = 0
		this_domain = self.map.keys()

		for obj in this_domain:
			domain_element = obj
			this_range_set = self.map[domain_element]
			size += len(this_range_set)
			
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

		_range = self.map[prj1]

		return BBoolean(prj2 in _range)

	def notElementOf(self, obj: 'BTuple') -> 'BBoolean':
		prj1 = obj.projection1()
		prj2 = obj.projection2()

		domain = self.map.keys()

		if prj1 not in domain:
			return BBoolean(True)

		_range = self.map[prj1]

		return BBoolean(prj2 not in _range)
	
	def relationImage(self, domain: 'BSet') -> 'BSet':
		result_set = set()
		for domain_element in domain:
			this_range_set = self.map[domain_element]
			if this_range_set is None:
				continue
			result_set = result_set.union(this_range_set)
		return BSet(*result_set)

	def functionCall(self, arg):
		_range = self.map.get(arg)
		if _range is None:
			raise Exception("Argument is not in the domain of this relation")
		
		for element in _range:
			return element
		raise Exception("Argument is not in the domain of this relation")
	
	def pow(self) -> 'BSet':
		this_map = self.map
		this_domain = this_map.keys()

		start = BRelation()
		queue = [start]
		result = BSet(start)
		while not len(queue) == 0:
			current_set = queue.pop(0)

			for e1 in this_domain:
				domain_element = e1
				_range = this_map[domain_element]
				for e2 in _range:
					range_element = e2
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
		_set = self.map.keys()
		result_set = _set
		for obj in _set:
			domain_element = obj
			_range = this_map[domain_element]
			if len(_range) == 0:
				result_set = result_set.difference([domain_element])
		return BSet(*list(result_set))

	def _range(self) -> 'BSet':
		_set = reduce(lambda a, b: a.union(b), self.map.values(), set())
		return BSet(*list(_set))

	def inverse(self) -> 'BRelation':
		this_map = self.map
		keys = this_map.keys()

		result_map = {}
		for e1 in keys:
			domain_element = e1
			_range = this_map[domain_element]
			for e2 in _range:
				range_element = e2
				current_range = result_map.get(range_element)
				if current_range is None:
					current_range = set()
				current_range = current_range.union([domain_element])
				result_map[range_element] = current_range
		return BRelation(result_map)

	def domainRestriction(self, arg: 'BSet') -> 'BRelation':
		_set = set(self.map.keys())
		other_set = arg.getSet()
		result_set = _set.difference(other_set)
		result_map = self.map
		for obj in result_set:
			result_map.pop(obj, None)
		return BRelation(result_map)

	def domainSubstraction(self, arg: 'BSet') -> 'BRelation':
		_set = self.map.keys()
		other_set = arg.getSet()
		result_map = self.map
		for obj in other_set:
			result_map.pop(obj, None)
		return BRelation(result_map)
	
	def rangeRestriction(self, arg: 'BSet') -> 'BRelation':
		other_set = arg.getSet()
		this_domain = self.map.keys()

		result_map = self.map
		for obj in this_domain:
			domain_element = obj
			this_range_set = self.map[domain_element]
			result_map[domain_element] = this_range_set.intersection(other_set)
		return BRelation(result_map)

	def rangeSubstraction(self, arg: 'BSet') -> 'BRelation':
		other_set = arg.getSet()
		this_domain = self.map.keys()

		result_map = self.map
		for obj in this_domain:
			domain_element = obj
			this_range_set = self.map[domain_element]
			result_map[domain_element] = this_range_set.difference(other_set)
		return BRelation(result_map)

	def override(self, arg: 'BRelation') -> 'BRelation':
		other_map = arg.map

		other_domain = other_map.keys()

		result_map = self.map
		for obj in other_domain:
			domain_element = obj
			_range = other_map[domain_element]
			result_map[domain_element] = _range

		return BRelation(result_map)
	
	def first(self):
		return self.functionCall(BInteger(1))

	def last(self):
		return self.functionCall(self.card())

	def reverse(self) -> 'BRelation':
		size = self.card()
		result_map = {}
		for i in map(BInteger, range(1, size.intValue() + 1)):
			range_element = self.functionCall(size.minus(i).succ())
			result_map[i] = {range_element}
		return BRelation(result_map)

	def front(self) -> 'BRelation':
		return self.domainSubstraction(BSet(self.card()))

	def tail(self) -> 'BRelation':
		size = self._size().intValue()
		result_map = {}
		for i in map(BInteger, range(2, size+1)):
			range_element = self.functionCall(i)
			result_map[i.pred()] = {range_element}
		return BRelation(result_map)
	
	def take(self, n: 'BInteger') -> 'BRelation':
		size = self._size()
		if n.greaterEqual(size).booleanValue():
			return BRelation(self.map)
		result_map = self.map
		# Remove sets with index greater than n
		for i in map(BInteger, range(n.intValue() + 1, size.intValue() + 1)):
			result_map.pop(i, None)
		return BRelation(result_map)

	def drop(self, n: 'BInteger') -> 'BRelation':
		size = self._size().intValue()
		this_map = self.map
		result_map = {}
		for i in map(BInteger, range(n.intValue() + 1, size + 1)):
			current_set = this_map[i]
			result_map[i.minus(n)] = current_set
		return BRelation(result_map)

	def concat(self, arg: 'BRelation') -> 'BRelation':
		result_map = self.map
		other_map = arg.map
		size = self.card()
		for i in map(BInteger, range(1, arg._size().intValue() + 1)):
			result_map[size.plus(i)] = other_map[i]
		return BRelation(result_map)

	def conc(self) -> 'BRelation':
		result = BRelation()
		size = self.card().intValue()
		for i in map(BInteger, range(1, size + 1)):
			result = result.concat(self.functionCall(i))
		return result

	def append(self, arg) -> 'BRelation':
		result_map = self.map
		result_map[self.card().succ()] = {arg}
		return BRelation(result_map)

	def prepend(self, arg) -> 'BRelation':
		result_map = {}
		this_map = self.map
		size = self._size().intValue()
		for i in map(BInteger, range(1, size + 1)):
			result_map[i.succ()] = this_map[i]
		result_map[BInteger(1)] = {arg}
		return BRelation(result_map)

	def directProduct(self, arg: 'BRelation') -> 'BRelation':
		this_map = self.map
		this_domain = this_map.keys()
		other_map = arg.map

		result_map = {}
		for obj in this_domain:
			domain_element = obj
			this_range = this_map.get(domain_element, None)
			other_range = other_map.get(domain_element, None)
			if other_range is None:
				continue
			result_range = set()
			for lhs in this_range:
				for rhs in other_range:
					lhs_element = lhs
					rhs_element = rhs
					result_range = result_range.union([BTuple(lhs_element, rhs_element)])
			result_map[domain_element] = result_range
		return BRelation(result_map)
	
	def parallelProduct(self, arg: 'BRelation') -> 'BRelation':
		this_map = self.map
		this_domain = this_map.keys()

		other_map = arg.map
		other_domain = other_map.keys()

		result_map = {}

		for domain_elementThis in this_domain:
			for domaineElementOther in other_domain:
				domain_element_this_element = domain_elementThis
				domain_element_other_element = domaineElementOther

				this_range = this_map[domain_element_this_element]
				other_range = other_map[domain_element_other_element]

				result_range = set()
				for lhs in this_range:
					for rhs in other_range:
						lhs_element = lhs
						rhs_element = rhs
						result_range = result_range.union([BTuple(lhs_element, rhs_element)])
				_tuple = BTuple(domain_element_this_element, domain_element_other_element)
				result_map[_tuple] = result_range
		return BRelation(result_map)

	def composition(self, arg: 'BRelation') -> 'BRelation':
		this_map = self.map
		other_map = arg.map

		this_domain = this_map.keys()

		result_map = {}

		for e1 in this_domain:
			domain_element = e1
			_range = this_map[domain_element]

			_set = set()
			for e2 in _range:
				range_element = e2
				union_element = other_map.get(range_element)
				if union_element is None:
					union_element = set()
				_set = _set.union(union_element)
			result_map[domain_element] = _set
		return BRelation(result_map)

	def iterate(self, n: 'BInteger') -> 'BRelation':
		this_relation = self
		result = self.identity(self.domain())
		for _ in map(BInteger, range(1, n.intValue() + 1)):
			result = result.union(result.composition(this_relation))
		return result

	def closure(self) -> 'BRelation':
		this_relation = self
		result = self.identity(self.domain())
		next_result = result.composition(this_relation)
		while True:
			last_result = deepcopy(result)
			result = result.union(next_result)
			next_result = result.composition(this_relation)
			if result.equal(last_result).booleanValue():
				break
		return result

	def closure1(self) -> 'BRelation':
		this_relation = self
		result = self
		next_result = result.composition(this_relation)
		while True:
			last_result = deepcopy(result)
			result = result.union(next_result)
			next_result = result.composition(this_relation)
			if result.equal(last_result).booleanValue():
				break
		return result

	@staticmethod
	def projection1(arg1: 'BSet', arg2: 'BSet') -> 'BRelation':
		arg_set_1 = arg1.getSet()
		arg_set_2 = arg2.getSet()

		result_map = {}
		for e1 in arg_set_1:
			for e2 in arg_set_2:
				element1 = e1
				element2 = e2

				_tuple = BTuple(element1, element2)
				result_map[_tuple] = {element1}
		return BRelation(result_map)

	@staticmethod
	def projection2(arg1: 'BSet', arg2: 'BSet') -> 'BRelation':
		arg_set_1 = arg1.getSet()
		arg_set_2 = arg2.getSet()

		result_map = {}
		for e1 in arg_set_1:
			for e2 in arg_set_2:
				element1 = e1
				element2 = e2

				_tuple = BTuple(element1, element2)
				result_map[_tuple] = {element2}
		return BRelation(result_map)
	
	def fnc(self) -> 'BRelation':
		this_map = self.map
		domain = self.domain().getSet()

		result_map = {}
		for e in domain:
			domain_element = e
			_range = this_map[e]
			range_set = BSet(_range)
			result_map[domain_element] = {range_set}
		return BRelation(result_map)

	def rel(self) -> 'BRelation':
		domain = self.domain()

		result_map = {}
		for domain_element in domain:
			_range = self.functionCall(domain_element)
			range_set = _range.getSet()
			result_map[domain_element] = range_set
		return BRelation(result_map)

	@staticmethod
	def identity(arg: 'BSet') -> 'BRelation':
		result_map = {}
		for e in arg:
			result_map[e] = {e}
		return BRelation(result_map)

	@staticmethod
	def cartesianProduct(arg1: 'BSet', arg2: 'BSet') -> 'BRelation':
		result_map = {}
		for e1 in arg1:
			result_map[e1] = arg2.getSet()
		return BRelation(result_map)
	
	def nondeterminism(self) -> 'BTuple':
		domain = self.map.keys()

		index = random.choice(range(len(domain)))
		i = 0
		domain_element = None
		for obj in domain:
			if i == index:
				domain_element = obj
				break
			i = i + 1

		_range = self.map[domain_element]
		index = random.choice(range(_range.size()))
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
			if(isinstance(e, BInteger)):
				return BBoolean(True)
			else:
				return BBoolean(False)
		return BBoolean(True)

	def isPartialNatural(self):
		for e in self.domain():
			if(isinstance(e, BInteger) and not e.isNatural().booleanValue()):
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
		visited = set()
		for element in self.domain():
			_range = self.map[element]
			for e in _range:
				range_element = e
				if range_element in visited:
					return BBoolean(False)
				visited = visited.union([range_element])
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
		domain = this_map.keys()

		size = self.size()
		i = 0

		sb = "{"
		for e1 in domain:
			domain_element = e1
			_range = this_map[domain_element]
			for e2 in _range:
				range_element = e2
				sb += "("
				sb += str(domain_element)
				sb += " |-> "
				sb += str(range_element)
				sb += ")"
				if i+1 < size:
					sb += ", "
				i = i + 1
		sb += "}"
		return sb
