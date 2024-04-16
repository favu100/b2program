MACHINE FinEmptySet

VARIABLES  f

INVARIANT  f <: POW(INTEGER)

INITIALISATION f := {{1,2}}

OPERATIONS

	calculate = BEGIN f := FIN({}) END;
	out <-- getRes = out := card(f)

END