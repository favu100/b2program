MACHINE NotSubsetOfNat1

VARIABLES  x

INVARIANT  x <: NAT

INITIALISATION x := {-1,1,2}

OPERATIONS

	op = SELECT x /<: NAT1 THEN x := {1} END;
	out <-- getRes = out := x

END