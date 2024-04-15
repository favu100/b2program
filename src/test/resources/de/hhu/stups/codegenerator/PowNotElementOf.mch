MACHINE PowNotElementOf

VARIABLES  f

INVARIANT  f : POW({1,2,3,4,5})

INITIALISATION f := {1}

OPERATIONS

	calculate = SELECT f /: POW(10..15) THEN f := {1,2,3} END;
	out <-- getRes = out := card(f)

END