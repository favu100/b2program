MACHINE Pow

SETS F = {ONE, TWO, THREE}

VARIABLES  r

INVARIANT  r <: POW(F)

INITIALISATION r := {}

OPERATIONS

	calculate = BEGIN r := POW(F) END;
	out <-- getRes = out := card(r)

END