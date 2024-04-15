MACHINE IsNotInUnion

VARIABLES  x

INVARIANT  x : 0..5

INITIALISATION x := 5

OPERATIONS

	op = SELECT x /: 0..4 \/ 6..10 THEN x := 1 END;
	out <-- getRes = out := x

END