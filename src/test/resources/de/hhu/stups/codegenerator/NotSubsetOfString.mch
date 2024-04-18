MACHINE NotSubsetOfString

VARIABLES  x

INVARIANT  x <: STRING

INITIALISATION x := {"Hallo", "Welt"}

OPERATIONS

	op = IF x /<: STRING THEN x := {"Hallo"} ELSE x := {"Welt"} END;
	out <-- getRes = out := x

END