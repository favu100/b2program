MACHINE NotNat

VARIABLES  x

INVARIANT  x : NAT

INITIALISATION x := -1

OPERATIONS

	op = IF x /: NAT THEN x := 0 ELSE x := 1 END;
	out <-- getRes = out := x

END