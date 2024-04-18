MACHINE SubsetOfString

VARIABLES  x

INVARIANT  x <: STRING

INITIALISATION x := {"Hallo", "Welt"}

OPERATIONS

	op = SELECT x <: STRING THEN x := {"Hallo"} END;
	out <-- getRes = out := x

END