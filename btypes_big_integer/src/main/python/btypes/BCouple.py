class BCouple:

    def __init__(self, first, second):
        self.__first = first
        self.__second = second

    def get_first(self):
        return self.__first

    def get_second(self):
        return self.__second

    def __eq__(self, other):
        return self.__first == other.__first and self.__second == other.__second

    def equal(self, other):
        return self == other

    def unequal(self, other):
        return self != other