MACHINE IfExpression

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 1

OPERATIONS

	calculate = x := IF x > 0 THEN 0 ELSE 1 END;

	out <-- getRes = out := x

END