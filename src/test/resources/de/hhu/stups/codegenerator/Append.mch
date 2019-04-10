MACHINE Append

VARIABLES  f

INVARIANT  f : seq(INT)

INITIALISATION f := [1,2,3]

OPERATIONS

	calculate = BEGIN f := f<-4 END;
	out <-- getRes = out := card(f)

END