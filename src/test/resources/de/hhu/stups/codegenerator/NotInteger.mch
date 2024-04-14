MACHINE NotInteger

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 0

OPERATIONS

	op = IF x /: INTEGER THEN x := 0 ELSE x := 1 END;
	out <-- getRes = out := x

END