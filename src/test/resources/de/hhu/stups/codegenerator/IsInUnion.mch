MACHINE IsInUnion

VARIABLES  x

INVARIANT  x : 0..5

INITIALISATION x := 0

OPERATIONS

	op = SELECT x : 0..5 \/ 5..10 THEN x := 1 END;
	out <-- getRes = out := x

END