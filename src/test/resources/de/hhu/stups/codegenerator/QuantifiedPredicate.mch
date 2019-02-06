MACHINE QuantifiedPredicate

VARIABLES  x

INVARIANT  x : 0..5

INITIALISATION x := 1

OPERATIONS

	calculate = SELECT #p.(p:0..5 & p < 5) THEN x := 1 END

END