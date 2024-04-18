MACHINE SubsetOfNatural

VARIABLES  x

INVARIANT  x <: NATURAL

INITIALISATION x := {1,2}

OPERATIONS

	op = SELECT x <: NATURAL THEN x := {1} END;
	out <-- getRes = out := x

END