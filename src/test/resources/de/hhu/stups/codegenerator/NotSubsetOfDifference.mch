MACHINE NotSubsetOfDifference

VARIABLES  x

INVARIANT  x <: 0..5

INITIALISATION x := {3}

OPERATIONS

	op = SELECT x /<: {0,3,4} - {0,1,2,3} THEN x := {1} END;
	out <-- getRes = out := x

END