MACHINE QuantifiedExpression4

VARIABLES  x

INVARIANT  x : POW(INTEGER)

INITIALISATION x := {0}

OPERATIONS

	calculate = BEGIN x := INTER (p).(p:{{1},{2},{3}}|p) END;
	out <-- getRes = out := card(x)

END