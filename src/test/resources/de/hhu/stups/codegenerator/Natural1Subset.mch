MACHINE Natural1Subset

VARIABLES  x

INVARIANT  x : POW(INTEGER)

INITIALISATION x := {1,2,3}

OPERATIONS

	op1 = SELECT x <: NATURAL1 THEN x := {1,2} END

END