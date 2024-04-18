MACHINE NotSubsetOfRange

VARIABLES  x

INVARIANT  x <: INTEGER

INITIALISATION x := {2}

OPERATIONS

	op = SELECT x /<: ran({1|->3, 0|->0}) THEN x := {1} END;
	out <-- getRes = out := x

END