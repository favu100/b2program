MACHINE Less

VARIABLES  x, y, r

INVARIANT  x : INT & y : INT & r : BOOL

INITIALISATION x := 1; y := 2; r := FALSE

OPERATIONS

	calculate = BEGIN r := bool(x < y) END;
	out <-- getRes = out := r

END