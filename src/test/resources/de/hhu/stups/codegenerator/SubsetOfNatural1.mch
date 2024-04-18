MACHINE SubsetOfNatural1

VARIABLES  x

INVARIANT  x <: NATURAL1

INITIALISATION x := {1,2}

OPERATIONS

	op = SELECT x <: NATURAL1 THEN x := {1} END;
	out <-- getRes = out := x

END