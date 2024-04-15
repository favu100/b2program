MACHINE NotInt

VARIABLES  x

INVARIANT  x : INT

INITIALISATION x := 0

OPERATIONS

	op = IF x /: INT THEN x := 0 ELSE x := 1 END;
	out <-- getRes = out := x

END