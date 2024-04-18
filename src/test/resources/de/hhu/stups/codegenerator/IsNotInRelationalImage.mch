MACHINE IsNotInRelationalImage

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 2

OPERATIONS

	op = SELECT x /: ({1|->1, 3|->1})[{3}] THEN x := 2 END;
	out <-- getRes = out := x

END