from btypes.BBoolean import BBoolean
from btypes.BSet import BSet
from btypes.BRelation import BRelation
from btypes.BTuple import BTuple
from btypes.BObject import BObject


from enum import Enum, auto


class BLOCKS(BObject, Enum):
    A = auto()
    B = auto()
    C = auto()
    D = auto()
    E = auto()
    F = auto()
    G = auto()
    H = auto()
    I = auto()
    J = auto()
    K = auto()
    L = auto()
    M = auto()
    N = auto()

    def equal(self, o):
        return BBoolean(self == o)

    def unequal(self, o):
        return BBoolean(self != o)

    def __str__(self):
                if self == BLOCKS.A:
                    return "A"
                if self == BLOCKS.B:
                    return "B"
                if self == BLOCKS.C:
                    return "C"
                if self == BLOCKS.D:
                    return "D"
                if self == BLOCKS.E:
                    return "E"
                if self == BLOCKS.F:
                    return "F"
                if self == BLOCKS.G:
                    return "G"
                if self == BLOCKS.H:
                    return "H"
                if self == BLOCKS.I:
                    return "I"
                if self == BLOCKS.J:
                    return "J"
                if self == BLOCKS.K:
                    return "K"
                if self == BLOCKS.L:
                    return "L"
                if self == BLOCKS.M:
                    return "M"
                if self == BLOCKS.N:
                    return "N"


from enum import Enum, auto


class ROUTES(BObject, Enum):
    R1 = auto()
    R2 = auto()
    R3 = auto()
    R4 = auto()
    R5 = auto()
    R6 = auto()
    R7 = auto()
    R8 = auto()
    R9 = auto()
    R10 = auto()

    def equal(self, o):
        return BBoolean(self == o)

    def unequal(self, o):
        return BBoolean(self != o)

    def __str__(self):
                if self == ROUTES.R1:
                    return "R1"
                if self == ROUTES.R2:
                    return "R2"
                if self == ROUTES.R3:
                    return "R3"
                if self == ROUTES.R4:
                    return "R4"
                if self == ROUTES.R5:
                    return "R5"
                if self == ROUTES.R6:
                    return "R6"
                if self == ROUTES.R7:
                    return "R7"
                if self == ROUTES.R8:
                    return "R8"
                if self == ROUTES.R9:
                    return "R9"
                if self == ROUTES.R10:
                    return "R10"


class Train_1_beebook_deterministic:



    _BLOCKS = BSet(BLOCKS.A, BLOCKS.B, BLOCKS.C, BLOCKS.D, BLOCKS.E, BLOCKS.F, BLOCKS.G, BLOCKS.H, BLOCKS.I, BLOCKS.J, BLOCKS.K, BLOCKS.L, BLOCKS.M, BLOCKS.N)
    _ROUTES = BSet(ROUTES.R1, ROUTES.R2, ROUTES.R3, ROUTES.R4, ROUTES.R5, ROUTES.R6, ROUTES.R7, ROUTES.R8, ROUTES.R9, ROUTES.R10)

    def __init__(self):
        self.fst = BRelation(BTuple(ROUTES.R1, BLOCKS.L), BTuple(ROUTES.R2, BLOCKS.L), BTuple(ROUTES.R3, BLOCKS.L), BTuple(ROUTES.R4, BLOCKS.M), BTuple(ROUTES.R5, BLOCKS.M), BTuple(ROUTES.R6, BLOCKS.C), BTuple(ROUTES.R7, BLOCKS.G), BTuple(ROUTES.R8, BLOCKS.N), BTuple(ROUTES.R9, BLOCKS.G), BTuple(ROUTES.R10, BLOCKS.N))
        self.lst = BRelation(BTuple(ROUTES.R1, BLOCKS.C), BTuple(ROUTES.R2, BLOCKS.G), BTuple(ROUTES.R3, BLOCKS.N), BTuple(ROUTES.R4, BLOCKS.G), BTuple(ROUTES.R5, BLOCKS.N), BTuple(ROUTES.R6, BLOCKS.L), BTuple(ROUTES.R7, BLOCKS.L), BTuple(ROUTES.R8, BLOCKS.L), BTuple(ROUTES.R9, BLOCKS.M), BTuple(ROUTES.R10, BLOCKS.M))
        self.nxt = BRelation(BTuple(ROUTES.R1, BRelation(BTuple(BLOCKS.L, BLOCKS.A), BTuple(BLOCKS.A, BLOCKS.B), BTuple(BLOCKS.B, BLOCKS.C))), BTuple(ROUTES.R2, BRelation(BTuple(BLOCKS.L, BLOCKS.A), BTuple(BLOCKS.A, BLOCKS.B), BTuple(BLOCKS.B, BLOCKS.D), BTuple(BLOCKS.D, BLOCKS.E), BTuple(BLOCKS.E, BLOCKS.F), BTuple(BLOCKS.F, BLOCKS.G))), BTuple(ROUTES.R3, BRelation(BTuple(BLOCKS.L, BLOCKS.A), BTuple(BLOCKS.A, BLOCKS.B), BTuple(BLOCKS.B, BLOCKS.D), BTuple(BLOCKS.D, BLOCKS.K), BTuple(BLOCKS.K, BLOCKS.J), BTuple(BLOCKS.J, BLOCKS.N))), BTuple(ROUTES.R4, BRelation(BTuple(BLOCKS.M, BLOCKS.H), BTuple(BLOCKS.H, BLOCKS.I), BTuple(BLOCKS.I, BLOCKS.K), BTuple(BLOCKS.K, BLOCKS.F), BTuple(BLOCKS.F, BLOCKS.G))), BTuple(ROUTES.R5, BRelation(BTuple(BLOCKS.M, BLOCKS.H), BTuple(BLOCKS.H, BLOCKS.I), BTuple(BLOCKS.I, BLOCKS.J), BTuple(BLOCKS.J, BLOCKS.N))), BTuple(ROUTES.R6, BRelation(BTuple(BLOCKS.C, BLOCKS.B), BTuple(BLOCKS.B, BLOCKS.A), BTuple(BLOCKS.A, BLOCKS.L))), BTuple(ROUTES.R7, BRelation(BTuple(BLOCKS.G, BLOCKS.F), BTuple(BLOCKS.F, BLOCKS.E), BTuple(BLOCKS.E, BLOCKS.D), BTuple(BLOCKS.D, BLOCKS.B), BTuple(BLOCKS.B, BLOCKS.A), BTuple(BLOCKS.A, BLOCKS.L))), BTuple(ROUTES.R8, BRelation(BTuple(BLOCKS.N, BLOCKS.J), BTuple(BLOCKS.J, BLOCKS.K), BTuple(BLOCKS.K, BLOCKS.D), BTuple(BLOCKS.D, BLOCKS.B), BTuple(BLOCKS.B, BLOCKS.A), BTuple(BLOCKS.A, BLOCKS.L))), BTuple(ROUTES.R9, BRelation(BTuple(BLOCKS.G, BLOCKS.F), BTuple(BLOCKS.F, BLOCKS.K), BTuple(BLOCKS.K, BLOCKS.I), BTuple(BLOCKS.I, BLOCKS.H), BTuple(BLOCKS.H, BLOCKS.M))), BTuple(ROUTES.R10, BRelation(BTuple(BLOCKS.N, BLOCKS.J), BTuple(BLOCKS.J, BLOCKS.I), BTuple(BLOCKS.I, BLOCKS.H), BTuple(BLOCKS.H, BLOCKS.M))))
        self._ic_set_0 = BRelation()
        for _ic_b_1 in self._BLOCKS:
            for _ic_r_1 in Train_1_beebook_deterministic._ROUTES:
                if(BBoolean(self.nxt.domain().elementOf(_ic_r_1).booleanValue() and BBoolean(self.nxt.functionCall(_ic_r_1).domain().elementOf(_ic_b_1).booleanValue() or self.nxt.functionCall(_ic_r_1)._range().elementOf(_ic_b_1).booleanValue()).booleanValue())).booleanValue():
                    _ic_set_0 = self._ic_set_0.union(BRelation(BTuple(_ic_b_1, _ic_r_1)))

        self.rtbl = self._ic_set_0
        self.resrt = BSet()
        self.resbl = BSet()
        self.rsrtbl = BRelation()
        self.OCC = BSet()
        self.TRK = BRelation()
        self.frm = BSet()
        self.LBT = BSet()

    def route_reservation(self, r):
        _ld_resrt = self.resrt

        _ld_rsrtbl = self.rsrtbl
        _ld_resbl = self.resbl
        self.resrt = _ld_resrt.union(BSet(r))
        self.rsrtbl = _ld_rsrtbl.union(self.rtbl.rangeRestriction(BSet(r)))
        self.resbl = _ld_resbl.union(self.rtbl.inverse().relationImage(BSet(r)))

    def route_freeing(self, r):
        _ld_resrt = self.resrt

        _ld_frm = self.frm
        self.resrt = _ld_resrt.difference(BSet(r))
        self.frm = _ld_frm.difference(BSet(r))

    def FRONT_MOVE_1(self, r):
        _ld_OCC = self.OCC
        _ld_LBT = self.LBT
        self.OCC = _ld_OCC.union(BSet(self.fst.functionCall(r)))
        self.LBT = _ld_LBT.union(BSet(self.fst.functionCall(r)))

    def FRONT_MOVE_2(self, b):
        self.OCC = self.OCC.union(BSet(self.TRK.functionCall(b)))

    def BACK_MOVE_1(self, b):
        _ld_OCC = self.OCC
        _ld_LBT = self.LBT
        _ld_rsrtbl = self.rsrtbl
        _ld_resbl = self.resbl
        self.OCC = _ld_OCC.difference(BSet(b))
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(BSet(b))
        self.resbl = _ld_resbl.difference(BSet(b))
        self.LBT = _ld_LBT.difference(BSet(b))

    def BACK_MOVE_2(self, b):
        _ld_OCC = self.OCC
        _ld_LBT = self.LBT
        _ld_rsrtbl = self.rsrtbl
        _ld_resbl = self.resbl
        self.OCC = _ld_OCC.difference(BSet(b))
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(BSet(b))
        self.resbl = _ld_resbl.difference(BSet(b))
        self.LBT = _ld_LBT.difference(BSet(b)).union(BSet(self.TRK.functionCall(b)))

    def point_positionning(self, r):
        self.TRK = self.TRK.domainSubstraction(self.nxt.functionCall(r).domain()).rangeSubstraction(self.nxt.functionCall(r)._range()).union(self.nxt.functionCall(r))

    def route_formation(self, r):
        self.frm = self.frm.union(BSet(r))


    def _get_LBT(self):
        return self.LBT

    def _get_TRK(self):
        return self.TRK

    def _get_frm(self):
        return self.frm

    def _get_OCC(self):
        return self.OCC

    def _get_resbl(self):
        return self.resbl

    def _get_resrt(self):
        return self.resrt

    def _get_rsrtbl(self):
        return self.rsrtbl


