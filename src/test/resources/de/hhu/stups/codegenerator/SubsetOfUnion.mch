MACHINE SubsetOfUnion

VARIABLES  x

INVARIANT  x <: 0..5

INITIALISATION x := {0}

OPERATIONS

	op = SELECT x <: {3,4} \/ {0,1,2,3} THEN x := {1} END;
	out <-- getRes = out := x

END