MACHINE IsInInverse

VARIABLES  x

INVARIANT  x : INTEGER * INTEGER

INITIALISATION x := 1 |-> 2

OPERATIONS

	op = SELECT x : {2|->1, 3|->1}~ THEN x := 2 |-> 2 END;
	out <-- getRes = out := x

END