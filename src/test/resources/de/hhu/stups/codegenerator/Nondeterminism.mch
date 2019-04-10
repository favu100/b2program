MACHINE Nondeterminism

VARIABLES  x, r

INVARIANT  x : POW(INT) & r : INT

INITIALISATION x := {1,2,3}; r := 0

OPERATIONS

	calculate = BEGIN r :: x END;
	out <-- getRes = out := card({r} /\ x)

END