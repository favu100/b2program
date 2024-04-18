MACHINE SubsetOfRange

VARIABLES  x

INVARIANT  x <: INTEGER

INITIALISATION x := {3}

OPERATIONS

	op = SELECT x <: ran({1|->3, 0|->0}) THEN x := {1} END;
	out <-- getRes = out := x

END