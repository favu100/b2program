MACHINE Fin

SETS F = {ONE, TWO, THREE}

VARIABLES  r

INVARIANT  r <: POW(F)

INITIALISATION r := {}

OPERATIONS

	calculate = BEGIN r := FIN(F) END;
	out <-- getRes = out := card(r)

END