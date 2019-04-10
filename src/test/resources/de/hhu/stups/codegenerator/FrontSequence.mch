MACHINE FrontSequence

VARIABLES  f, s

INVARIANT  f : seq(INT) & s : seq(INT)

INITIALISATION f := [1,2,3]; s := []

OPERATIONS

	calculate = BEGIN s:= front(f) END;
	out <-- getRes = out := card(s)

END