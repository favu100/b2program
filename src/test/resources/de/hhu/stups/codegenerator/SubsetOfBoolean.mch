MACHINE SubsetOfBoolean

VARIABLES  x

INVARIANT  x <: BOOL

INITIALISATION x := {TRUE}

OPERATIONS

	op = SELECT x <: BOOL THEN x := {FALSE} END;
	out <-- getRes = out := x

END