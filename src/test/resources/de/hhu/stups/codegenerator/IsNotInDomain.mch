MACHINE IsNotInDomain

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 5

OPERATIONS

	op = SELECT x /: dom({1|->1, 3|->1}) THEN x := 2 END;
	out <-- getRes = out := x

END