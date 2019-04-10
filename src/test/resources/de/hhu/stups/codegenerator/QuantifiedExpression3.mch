MACHINE QuantifiedExpression3

VARIABLES  x

INVARIANT  x : POW(INTEGER)

INITIALISATION x := {0}

OPERATIONS

	calculate = BEGIN x := UNION (p).(p:{{1},{2},{3}}|p) END;
	out <-- getRes = out := card(x)

END