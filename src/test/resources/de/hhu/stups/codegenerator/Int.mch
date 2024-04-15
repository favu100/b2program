MACHINE Int

VARIABLES  x

INVARIANT  x : INT

INITIALISATION x := 0

OPERATIONS

	op = SELECT x : INT THEN x := 1 END;
	out <-- getRes = out := x

END