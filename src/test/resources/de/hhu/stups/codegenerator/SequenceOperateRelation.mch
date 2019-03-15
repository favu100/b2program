MACHINE SequenceOperateRelation

VARIABLES  f,s

INVARIANT  f : seq(INT) & s : INT --> INT

INITIALISATION f := <>; s:= {(1|->2)}

OPERATIONS

	calculate = BEGIN f := f \/ s END

END