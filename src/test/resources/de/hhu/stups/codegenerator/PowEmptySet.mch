MACHINE PowEmptySet

VARIABLES  f

INVARIANT  f : POW(INT)

INITIALISATION f := POW({})

OPERATIONS

	calculate = BEGIN f := POW({}) END;
	out <-- getRes = out := card(f)

END