MACHINE QuantifiedPredicate4

VARIABLES  x

INVARIANT  x : 0..5

INITIALISATION x := 0

OPERATIONS

	calculate = SELECT !p.(p:0..5 => p < 6) THEN x := 1 END;
	out <-- getRes = out := x

END