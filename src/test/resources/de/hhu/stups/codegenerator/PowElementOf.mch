MACHINE PowElementOf

VARIABLES  f

INVARIANT  f : POW({1,2,3,4,5})

INITIALISATION f := {1}

OPERATIONS

	calculate = SELECT f : POW(1..5) THEN f := {1,2,3} END;
	out <-- getRes = out := card(f)

END