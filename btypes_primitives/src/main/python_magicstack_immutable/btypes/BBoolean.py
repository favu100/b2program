class BBoolean:
    def __init__(self, value):
        if type(value) is bool:
            self.__value = value
        elif type(value) is str:
            self.__value = str(value).lower() == "true"
        elif type(value) is BBoolean:
            self.__value = value.__value

    def __bool__(self) -> 'bool':
        return self.__value

    def __and__(self, other: 'BBoolean') -> 'BBoolean':
        return BBoolean(self.__value and other.__value)

    def __or__(self, other: 'BBoolean') -> 'BBoolean':
        return BBoolean(self.__value or other.__value)

    def __rand__(self, other: 'BBoolean') -> 'BBoolean':
        return BBoolean(self.__value and other.__value)

    def __str__(self) -> 'str':
        return str(self.__value).lower()

    def __ror__(self, other: 'BBoolean') -> 'BBoolean':
        return BBoolean(self.__value or other.__value)

    def __rxor__(self, other: 'BBoolean') -> 'BBoolean':
        return BBoolean(self.__value ^ other.__value)

    def __xor__(self, other: 'BBoolean') -> 'BBoolean':
        return BBoolean(self.__value ^ other.__value)

    def __eq__(self, other: 'BBoolean') -> 'BBoolean':
        if not isinstance(other, BBoolean):
            return BBoolean(False)
        return BBoolean(self.__value == other.__value)

    def __ne__(self, other: 'BBoolean') -> 'BBoolean':
        return BBoolean(self.__value != other.__value)

    def _and(self, other: 'BBoolean') -> 'BBoolean':
        return self.__and__(other)

    def _or(self, other: 'BBoolean') -> 'BBoolean':
        return self.__or__(other)

    def _not(self) -> 'BBoolean':
        return BBoolean(not self.__value)

    def implies(self, other: 'BBoolean') -> 'BBoolean':
        return self._not()._or(other)

    def equivalent(self, other: 'BBoolean') -> 'BBoolean':
        return self.implies(other)._and(other.implies(self))

    def equal(self, other: 'BBoolean') -> 'BBoolean':
        return self.__eq__(other)

    def unequal(self, other: 'BBoolean') -> 'BBoolean':
        return self.__ne__(other)

    def booleanValue(self) -> 'bool':
        return self.__value

    def __hash__(self):
        return hash(self.__value)
