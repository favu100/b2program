MACHINE QuantifiedExpression1

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 0

OPERATIONS

	calculate = BEGIN x := SIGMA (p).(p:0..5|p) END;
	out <-- getRes = out := x

END