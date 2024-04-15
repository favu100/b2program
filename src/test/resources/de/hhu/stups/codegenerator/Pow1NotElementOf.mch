MACHINE Pow1NotElementOf

VARIABLES  f

INVARIANT  f : POW1({1,2,3,4,5})

INITIALISATION f := {1}

OPERATIONS

	calculate = SELECT f /: POW1(10..15) THEN f := {1,2,3} END;
	out <-- getRes = out := card(f)

END