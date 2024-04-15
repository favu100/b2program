MACHINE Fin1NotElementOf

VARIABLES  f

INVARIANT  f : FIN1({1,2,3,4,5})

INITIALISATION f := {1}

OPERATIONS

	calculate = SELECT f /: FIN1(10..15) THEN f := {1,2,3} END;
	out <-- getRes = out := card(f)

END