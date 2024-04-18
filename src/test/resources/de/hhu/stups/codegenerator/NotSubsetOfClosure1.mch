MACHINE NotSubsetOfClosure1

VARIABLES  x

INVARIANT  x <: INTEGER * INTEGER

INITIALISATION x := {1 |-> 5}

OPERATIONS

	op = SELECT x /<: closure1({1 |-> 2, 2 |-> 3, 3 |-> 4}) THEN x := {2 |-> 2} END;
	out <-- getRes = out := x

END