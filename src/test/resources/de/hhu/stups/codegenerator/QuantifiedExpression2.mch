MACHINE QuantifiedExpression2

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 0

OPERATIONS

	calculate = BEGIN x := PI (p).(p:1..5|p) END;
	out <-- getRes = out := x

END