MACHINE PowEmptySet

VARIABLES  f

INVARIANT  f <: POW(INTEGER)

INITIALISATION f := {{1,2}}

OPERATIONS

	calculate = BEGIN f := POW({}) END;
	out <-- getRes = out := card(f)

END