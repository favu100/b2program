MACHINE FinElementOf

VARIABLES  f

INVARIANT  f : FIN({1,2,3,4,5})

INITIALISATION f := {1}

OPERATIONS

	calculate = SELECT f : FIN(1..5) THEN f := {1,2,3} END;
	out <-- getRes = out := card(f)

END