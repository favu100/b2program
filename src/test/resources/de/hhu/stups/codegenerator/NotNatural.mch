MACHINE NotNatural

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := -1

OPERATIONS

	op = SELECT x /: NATURAL THEN x := 0 END;
	out <-- getRes = out := x

END