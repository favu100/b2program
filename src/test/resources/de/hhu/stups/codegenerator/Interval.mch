MACHINE Interval

VARIABLES  x, r

INVARIANT  x : INT & r : POW(INT)

INITIALISATION x := 1; r := {}

OPERATIONS

	calculate = BEGIN r := x..5 END;
	out <-- getRes = out := card(r)

END