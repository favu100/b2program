MACHINE Natural1

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 1

OPERATIONS

	op = SELECT x : NATURAL1 THEN x := 2 END;
	out <-- getRes = out := x

END