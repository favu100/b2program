MACHINE QuantifiedPredicate2

VARIABLES  x

INVARIANT  x : 0..5

INITIALISATION x := 1

OPERATIONS

	calculate = WHILE #p.(p:0..5 & p < 5) & x < 10 DO x := x + 1 INVARIANT 1 = 1 VARIANT 10 -x END;
	out <-- getRes = out := x

END