MACHINE IsNotInInverse

VARIABLES  x

INVARIANT  x : INTEGER * INTEGER

INITIALISATION x := 2 |-> 1

OPERATIONS

	op = SELECT x /: {2|->1, 3|->1}~ THEN x := 2 |-> 2 END;
	out <-- getRes = out := x

END