from btypes.BBoolean import *

class BString:

	def __init__(self, value):
		self.__value = value

	def getValue(self):
		return value

	def __eq__(self, other: 'BString') -> 'BBoolean':
		return BBoolean(self.__value == other.__value)

	def equals(self, other) -> 'bool':
		return self.__eq__(other)

	def length(self) -> 'int':
		return len(self.__value)

	def isEmpty(self) -> 'bool':
		return not self.__value

	def hashCode(self):
		hash(self.__value)

    def equal(self, other: 'BString') -> 'BBoolean':
        return BBoolean(self.__value == other.__value)

    def unequal(self, other: 'BString') -> 'BBoolean':
        return BBoolean(self.__value != other.__value)

	def toString(self) -> 'str':
		return '"' + self.__value + '"'

	def isCase(self, other) -> 'bool':
		return self.__value.equals(other)

	def isString(self) -> 'BBoolean':
		return BBoolean(True)

	def isNotString(self) -> 'BBoolean':
		return BBoolean(False)
