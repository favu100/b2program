MACHINE SubsetOfInteger

VARIABLES  x

INVARIANT  x <: INTEGER

INITIALISATION x := {1,2}

OPERATIONS

	op = SELECT x <: INTEGER THEN x := {1} END;
	out <-- getRes = out := x

END