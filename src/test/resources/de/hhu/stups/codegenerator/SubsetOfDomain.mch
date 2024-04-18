MACHINE SubsetOfDomain

VARIABLES  x

INVARIANT  x <: INTEGER

INITIALISATION x := {0}

OPERATIONS

	op = SELECT x <: dom({1|->3, 0|->0}) THEN x := {1} END;
	out <-- getRes = out := x

END