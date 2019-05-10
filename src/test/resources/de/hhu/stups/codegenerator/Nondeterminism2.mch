MACHINE Nondeterminism2

VARIABLES  x, r

INVARIANT  x : POW(INT * INT) & r : INT * INT

INITIALISATION x := {1|->2, 2|->3, 3|->4}; r := 5|->6

OPERATIONS

	calculate = BEGIN r :: x END;
	out <-- getRes = out := card({r} /\ x)

END