MACHINE SubsetOfRelationalImage

VARIABLES  x

INVARIANT  x <: INTEGER

INITIALISATION x := {3}

OPERATIONS

	op = SELECT x <: {1|->3, 0|->0}[{1,2}] THEN x := {1} END;
	out <-- getRes = out := x

END