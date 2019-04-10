MACHINE Min

VARIABLES  x, r

INVARIANT  x : POW(INT) & r : INT

INITIALISATION x := {1,2}; r := 0

OPERATIONS

	calculate = BEGIN r := min(x) END;
	out <-- getRes = out := r

END