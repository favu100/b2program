MACHINE Prepend

VARIABLES  f

INVARIANT  f : seq(INT)

INITIALISATION f := [1,2,3]

OPERATIONS

	calculate = BEGIN f := 4->f END;
	out <-- getRes = out := card(f)

END