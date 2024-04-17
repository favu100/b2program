MACHINE IsInParallelProduct

VARIABLES  x

INVARIANT  x : (INTEGER * INTEGER) * (INTEGER * INTEGER)

INITIALISATION x := (1 |-> 1) |-> (1 |-> 2)

OPERATIONS

	op = SELECT x : ({1 |-> 1, 2 |-> 3} || {1 |-> 2, 2 |-> 4}) THEN x := (2 |-> 2) |-> (2 |-> 2) END;
	out <-- getRes = out := x

END