MACHINE NotSubsetOfIdentity

VARIABLES  x

INVARIANT  x <: INTEGER * INTEGER

INITIALISATION x := {3 |-> 1}

OPERATIONS

	op = SELECT x /<: id({1,2,3}) THEN x := {2 |-> 2} END;
	out <-- getRes = out := x

END