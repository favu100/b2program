MACHINE ReverseSequence

VARIABLES  f, s

INVARIANT  f : seq(INT) & s : seq(INT)

INITIALISATION f := [1,2,3]; s := []

OPERATIONS

	calculate = BEGIN s:= rev(f) END;
	out <-- getRes = out := first(s)

END