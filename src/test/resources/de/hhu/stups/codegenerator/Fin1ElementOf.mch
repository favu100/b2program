MACHINE Fin1ElementOf

VARIABLES  f

INVARIANT  f : FIN1({1,2,3,4,5})

INITIALISATION f := {1}

OPERATIONS

	calculate = SELECT f : FIN1(1..5) THEN f := {1,2,3} END;
	out <-- getRes = out := card(f)

END