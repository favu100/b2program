from btypes.BBoolean import BBoolean
from btypes.BSet import BSet
from btypes.BInteger import BInteger

class Sieve:

    def __init__(self):
        self.numbers = BSet.interval(BInteger(2), BInteger(2000000))
        self.cur = BInteger(2)
        self.limit = BInteger(2000000)

    def ComputeNumberOfPrimes(self):
        while (BBoolean(self.cur.greater(BInteger(1)).booleanValue() and self.cur.multiply(self.cur).lessEqual(self.limit).booleanValue())).booleanValue():
            if (self.numbers.elementOf(self.cur)).booleanValue():
                n = self.cur
                set = BSet()
                while (n.lessEqual(self.limit.divide(self.cur))).booleanValue():
                    set = set.union(BSet(self.cur.multiply(n)))
                    n = n.plus(BInteger(1))

                self.numbers = self.numbers.difference(set)

            self.cur = self.cur.plus(BInteger(1))

        res = self.numbers.card()
        return res


if __name__ == '__main__':
    sieve = Sieve()
    print(sieve.ComputeNumberOfPrimes())
