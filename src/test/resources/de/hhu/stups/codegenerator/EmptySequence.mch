MACHINE EmptySequence

VARIABLES  f

INVARIANT  f : seq(INT)

INITIALISATION f := <>

OPERATIONS

	calculate = BEGIN f := [] END;
	out <-- getRes = out := f

END