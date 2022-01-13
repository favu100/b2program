from btypes.BBoolean import BBoolean
from btypes.BSet import BSet
from btypes.BInteger import BInteger
from btypes.BRelation import BRelation
from btypes.BTuple import BTuple
from btypes.BObject import BObject


from enum import Enum, auto


class T1state(BObject, Enum):
    T1_EN = auto()
    T1_CALC = auto()
    T1_SEND = auto()
    T1_WAIT = auto()


    def equal(self, o):
        return BBoolean(self == o)

    def unequal(self, o):
        return BBoolean(self != o)

    def __str__(self):
                if self == T1state.T1_EN:
                    return "T1_EN"
                if self == T1state.T1_CALC:
                    return "T1_CALC"
                if self == T1state.T1_SEND:
                    return "T1_SEND"
                if self == T1state.T1_WAIT:
                    return "T1_WAIT"


from enum import Enum, auto


class T2mode(BObject, Enum):
    T2MODE_SENSE = auto()
    T2MODE_TRANSMIT = auto()
    T2MODE_RELEASE = auto()


    def equal(self, o):
        return BBoolean(self == o)

    def unequal(self, o):
        return BBoolean(self != o)

    def __str__(self):
                if self == T2mode.T2MODE_SENSE:
                    return "T2MODE_SENSE"
                if self == T2mode.T2MODE_TRANSMIT:
                    return "T2MODE_TRANSMIT"
                if self == T2mode.T2MODE_RELEASE:
                    return "T2MODE_RELEASE"


from enum import Enum, auto


class T2state(BObject, Enum):
    T2_EN = auto()
    T2_RCV = auto()
    T2_PROC = auto()
    T2_CALC = auto()
    T2_SEND = auto()
    T2_WAIT = auto()
    T2_RELEASE = auto()

    def equal(self, o):
        return BBoolean(self == o)

    def unequal(self, o):
        return BBoolean(self != o)

    def __str__(self):
                if self == T2state.T2_EN:
                    return "T2_EN"
                if self == T2state.T2_RCV:
                    return "T2_RCV"
                if self == T2state.T2_PROC:
                    return "T2_PROC"
                if self == T2state.T2_CALC:
                    return "T2_CALC"
                if self == T2state.T2_SEND:
                    return "T2_SEND"
                if self == T2state.T2_WAIT:
                    return "T2_WAIT"
                if self == T2state.T2_RELEASE:
                    return "T2_RELEASE"


from enum import Enum, auto


class T3state(BObject, Enum):
    T3_READY = auto()
    T3_WRITE = auto()
    T3_RELEASE = auto()
    T3_READ = auto()
    T3_PROC = auto()
    T3_WAIT = auto()

    def equal(self, o):
        return BBoolean(self == o)

    def unequal(self, o):
        return BBoolean(self != o)

    def __str__(self):
                if self == T3state.T3_READY:
                    return "T3_READY"
                if self == T3state.T3_WRITE:
                    return "T3_WRITE"
                if self == T3state.T3_RELEASE:
                    return "T3_RELEASE"
                if self == T3state.T3_READ:
                    return "T3_READ"
                if self == T3state.T3_PROC:
                    return "T3_PROC"
                if self == T3state.T3_WAIT:
                    return "T3_WAIT"


class CAN_BUS_tlc:



    _T1state = BSet(T1state.T1_EN, T1state.T1_CALC, T1state.T1_SEND, T1state.T1_WAIT)
    _T2mode = BSet(T2mode.T2MODE_SENSE, T2mode.T2MODE_TRANSMIT, T2mode.T2MODE_RELEASE)
    _T2state = BSet(T2state.T2_EN, T2state.T2_RCV, T2state.T2_PROC, T2state.T2_CALC, T2state.T2_SEND, T2state.T2_WAIT, T2state.T2_RELEASE)
    _T3state = BSet(T3state.T3_READY, T3state.T3_WRITE, T3state.T3_RELEASE, T3state.T3_READ, T3state.T3_PROC, T3state.T3_WAIT)

    def __init__(self):
        NATSET = BSet.interval(BInteger(0),BInteger(5))
        self.T2v = BInteger(0)
        self.T3_evaluated = BBoolean(True)
        self.T3_enabled = BBoolean(True)
        self.T1_state = T1state.T1_EN
        self.T2_state = T2state.T2_EN
        self.T3_state = T3state.T3_READY
        self.T1_writevalue = BInteger(0)
        self.T2_writevalue = BInteger(0)
        self.T2_readvalue = BInteger(0)
        self.T2_readpriority = BInteger(0)
        self.T3_readvalue = BInteger(0)
        self.T3_readpriority = BInteger(0)
        self.T1_timer = BInteger(2)
        self.T2_timer = BInteger(3)
        self.BUSwrite = BRelation(BTuple(BInteger(0), BInteger(0)))
        self.BUSvalue = BInteger(0)
        self.BUSpriority = BInteger(0)
        self.T2_mode = T2mode.T2MODE_SENSE

    def T1Evaluate(self):
        self.T1_timer = BInteger(0)
        self.T1_state = T1state.T1_CALC

    def T1Calculate(self, p):
        self.T1_writevalue = p
        self.T1_state = T1state.T1_SEND

    def T1SendResult(self, ppriority, pv):
        _ld_BUSwrite = self.BUSwrite
        self.BUSwrite = _ld_BUSwrite.override(BRelation(BTuple(ppriority, pv)))
        self.T1_state = T1state.T1_WAIT

    def T1Wait(self, pt):
        self.T1_timer = pt
        self.T1_state = T1state.T1_EN

    def T2Evaluate(self):
        self.T2_timer = BInteger(0)
        self.T2_state = T2state.T2_RCV

    def T2ReadBus(self, ppriority, pv):
        self.T2_readvalue = pv
        self.T2_readpriority = ppriority
        self.T2_state = T2state.T2_PROC

    def T2Reset(self):
        _ld_T2v = self.T2v
        self.T2_writevalue = _ld_T2v
        self.T2v = BInteger(0)
        self.T2_state = T2state.T2_SEND
        self.T2_mode = T2mode.T2MODE_TRANSMIT

    def T2Complete(self):
        self.T2_state = T2state.T2_RELEASE
        self.T2_mode = T2mode.T2MODE_SENSE

    def T2ReleaseBus(self, ppriority):
        _ld_BUSwrite = self.BUSwrite
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(BSet(ppriority))
        self.T2_state = T2state.T2_WAIT

    def T2Calculate(self):
        self.T2v = self.T2_readvalue
        self.T2_state = T2state.T2_WAIT

    def T2WriteBus(self, ppriority, pv):
        _ld_BUSwrite = self.BUSwrite
        self.BUSwrite = _ld_BUSwrite.override(BRelation(BTuple(ppriority, pv)))
        self.T2_state = T2state.T2_WAIT

    def T2Wait(self, pt):
        self.T2_timer = pt
        self.T2_state = T2state.T2_EN

    def T3Initiate(self):
        self.T3_state = T3state.T3_WRITE
        self.T3_enabled = BBoolean(False)

    def T3Evaluate(self):
        self.T3_state = T3state.T3_READ

    def T3writebus(self, ppriority, pv):
        _ld_BUSwrite = self.BUSwrite
        self.BUSwrite = _ld_BUSwrite.override(BRelation(BTuple(ppriority, pv)))
        self.T3_state = T3state.T3_WAIT

    def T3Read(self, ppriority, pv):
        self.T3_readvalue = pv
        self.T3_readpriority = ppriority
        self.T3_state = T3state.T3_PROC

    def T3Poll(self):
        self.T3_state = T3state.T3_WAIT

    def T3ReleaseBus(self, ppriority):
        _ld_BUSwrite = self.BUSwrite
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(BSet(ppriority))
        self.T3_state = T3state.T3_RELEASE

    def T3Wait(self):
        self.T3_state = T3state.T3_READY
        self.T3_evaluated = BBoolean(True)

    def T3ReEnableWait(self):
        self.T3_state = T3state.T3_READY
        self.T3_evaluated = BBoolean(True)
        self.T3_enabled = BBoolean(True)

    def Update(self, pmax):
        _ld_T2_timer = self.T2_timer
        _ld_T1_timer = self.T1_timer
        self.BUSvalue = self.BUSwrite.functionCall(pmax)
        self.BUSpriority = pmax
        self.T1_timer = _ld_T1_timer.minus(BInteger(1))
        self.T2_timer = _ld_T2_timer.minus(BInteger(1))
        self.T3_evaluated = BBoolean(False)

    def _get_BUSpriority(self):
        return self.BUSpriority

    def _get_BUSvalue(self):
        return self.BUSvalue

    def _get_BUSwrite(self):
        return self.BUSwrite

    def _get_T1_state(self):
        return self.T1_state

    def _get_T1_timer(self):
        return self.T1_timer

    def _get_T1_writevalue(self):
        return self.T1_writevalue

    def _get_T2_mode(self):
        return self.T2_mode

    def _get_T2_readpriority(self):
        return self.T2_readpriority

    def _get_T2_readvalue(self):
        return self.T2_readvalue

    def _get_T2_state(self):
        return self.T2_state

    def _get_T2_timer(self):
        return self.T2_timer

    def _get_T2_writevalue(self):
        return self.T2_writevalue

    def _get_T2v(self):
        return self.T2v

    def _get_T3_enabled(self):
        return self.T3_enabled

    def _get_T3_evaluated(self):
        return self.T3_evaluated

    def _get_T3_readpriority(self):
        return self.T3_readpriority

    def _get_T3_readvalue(self):
        return self.T3_readvalue

    def _get_T3_state(self):
        return self.T3_state


