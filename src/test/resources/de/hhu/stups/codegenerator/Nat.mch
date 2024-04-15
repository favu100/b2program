MACHINE Nat

VARIABLES  x

INVARIANT  x : NAT

INITIALISATION x := 0

OPERATIONS

	op = SELECT x : NAT THEN x := 1 END;
	out <-- getRes = out := x

END