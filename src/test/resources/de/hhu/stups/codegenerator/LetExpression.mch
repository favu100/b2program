MACHINE LetExpression

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 0

OPERATIONS

	calculate = x := LET a,b BE a = 1 & b = 2 IN a + b END;

	out <-- getRes = out := x

END