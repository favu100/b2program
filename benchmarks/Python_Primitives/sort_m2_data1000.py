from btypes.BRelation import BRelation
from btypes.BSet import BSet
from btypes.BTuple import BTuple
from btypes.BInteger import BInteger
from btypes.BBoolean import BBoolean



class sort_m2_data1000:
    def __init__(self):
        self._ic_set_0 = BRelation()
        for _ic_i in BSet.interval(BInteger(1), BInteger(1000)):
            self._ic_set_0 = self._ic_set_0.union(BRelation(BTuple(_ic_i, BInteger(1500).minus(_ic_i))))
        self.f = self._ic_set_0
        self.n = BInteger(1000)
        self.g = self.f
        self.k = BInteger(1)
        self.l = BInteger(1)
        self.j = BInteger(1)

    def progress(self):
        if BBoolean(self.k.unequal(self.n).booleanValue() and self.j.equal(self.n).booleanValue()).booleanValue():
            _ld_g = self.g
            _ld_k = self.k
            _ld_l = self.l
            self.g = _ld_g.override(BRelation(BTuple(_ld_k, _ld_g.functionCall(_ld_l))).override(BRelation(BTuple(_ld_l, _ld_g.functionCall(_ld_k)))))
            self.k = _ld_k.plus(BInteger(1))
            self.j = _ld_k.plus(BInteger(1))
            self.l = _ld_k.plus(BInteger(1))

    def prog1(self):
        if (BBoolean(BBoolean(self.k.unequal(self.n).booleanValue() and
                              self.j.unequal(self.n).booleanValue()).booleanValue() and
                              self.g.functionCall(self.l).lessEqual(self.g.functionCall(self.j.plus(BInteger(1)))).booleanValue())).booleanValue():
            _ld_j = self.j
            _ld_l = self.l
            self.l = _ld_l
            self.j = _ld_j.plus(BInteger(1))

    def prog2(self):
        if BBoolean(BBoolean(self.k.unequal(self.n).booleanValue() and
                             self.j.unequal(self.n).booleanValue()).booleanValue() and
                             self.g.functionCall(self.l).greater(self.g.functionCall(self.j.plus(BInteger(1)))).booleanValue()).booleanValue():
            _ld_j = self.j
            self.j = _ld_j.plus(BInteger(1))
            self.l = _ld_j.plus(BInteger(1))

    def final_evt(self):
        if (self.k.equal(self.n)).booleanValue():
            pass
