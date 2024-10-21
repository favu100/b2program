MACHINE QuantifiedPredicate8

VARIABLES  x

INVARIANT  x : 0..5

INITIALISATION x := 0

OPERATIONS

	calculate = SELECT !p.(p : {1,p} => p < 5) THEN x := 1 END

END