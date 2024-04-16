MACHINE IsNotInCartesianProduct

VARIABLES  x

INVARIANT  x : INTEGER * INTEGER

INITIALISATION x := 1 |-> 2

OPERATIONS

	op = SELECT x /: {1,3} * {3} THEN x := 2 |-> 2 END;
	out <-- getRes = out := x

END