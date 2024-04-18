MACHINE NotSubsetOfInteger

VARIABLES  x

INVARIANT  x <: INTEGER

INITIALISATION x := {1,2}

OPERATIONS

	op = IF x /<: INTEGER THEN x := {1} ELSE x := {0} END;
	out <-- getRes = out := x

END