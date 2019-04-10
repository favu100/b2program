MACHINE Concat

VARIABLES  f, s

INVARIANT  f : seq(INT) & s : seq(INT)

INITIALISATION f := [1,2,3]; s := [4,5]

OPERATIONS

	calculate = BEGIN f := f^s END;
	out <-- getRes = out := card(f)

END