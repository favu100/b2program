MACHINE NotSubsetOfBoolean

VARIABLES  x

INVARIANT  x <: BOOL

INITIALISATION x := {TRUE}

OPERATIONS

	op = IF x /<: BOOL THEN x := {FALSE} ELSE x := {} END;
	out <-- getRes = out := x

END