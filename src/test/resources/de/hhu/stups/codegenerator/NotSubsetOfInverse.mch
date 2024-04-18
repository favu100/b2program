MACHINE NotSubsetOfInverse

VARIABLES  x

INVARIANT  x <: INTEGER * INTEGER

INITIALISATION x := {3|->1}

OPERATIONS

	op = SELECT x /<: {1|->4, 0|->0}~ THEN x := {1|->1} END;
	out <-- getRes = out := x

END