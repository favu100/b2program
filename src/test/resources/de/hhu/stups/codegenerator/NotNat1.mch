MACHINE NotNat1

VARIABLES  x

INVARIANT  x : NAT1

INITIALISATION x := -1

OPERATIONS

	op = IF x /: NAT1 THEN x := 0 ELSE x := 1 END;
	out <-- getRes = out := x

END