class BBoolean:

    def __init__(self, value):
        self.__value = value

    def _and(self, o):
        return BBoolean(self.__value and o.__value)

    def _or(self, o):
        return BBoolean(self.__value or o.__value)

    def implies(self, o):
        return BBoolean(not self.__value or o.__value)

    def equivalent(self, o):
        return BBoolean(self.__value == o.__value)

    def equal(self, o):
        return BBoolean(self.__value  == o.__value)

    def unequal(self, o):
        return BBoolean(self.__value != o.__value)

    def _not(self, o):
        return BBoolean(not self.__value)