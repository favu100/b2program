MACHINE EmptySet

VARIABLES  f

INVARIANT  f : POW(INT)

INITIALISATION f := {}

OPERATIONS

	calculate = BEGIN f := {} END;
	out <-- getRes = out := f

END