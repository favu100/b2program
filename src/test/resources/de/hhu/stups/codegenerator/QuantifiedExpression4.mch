MACHINE QuantifiedExpression4

SETS EINT = {ZERO, ONE, TWO, THREE}

VARIABLES  x

INVARIANT  x : POW(EINT)

INITIALISATION x := {ZERO}

OPERATIONS

	calculate = BEGIN x := INTER (p).(p:{{ONE},{TWO},{THREE}}|p) END;
	out <-- getRes = out := card(x)

END