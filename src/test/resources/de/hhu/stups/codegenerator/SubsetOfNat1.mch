MACHINE SubsetOfNat1

VARIABLES  x

INVARIANT  x <: NAT1

INITIALISATION x := {1,2}

OPERATIONS

	op = SELECT x <: NAT1 THEN x := {1} END;
	out <-- getRes = out := x

END