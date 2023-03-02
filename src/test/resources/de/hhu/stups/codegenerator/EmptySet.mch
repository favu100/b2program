MACHINE EmptySet

SETS S={S1}

VARIABLES  f

INVARIANT  f : POW(S)

INITIALISATION f := {}

OPERATIONS

	calculate = BEGIN f := {} END;
	out <-- getRes = out := f

END