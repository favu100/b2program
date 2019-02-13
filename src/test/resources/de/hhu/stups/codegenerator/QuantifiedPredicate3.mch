MACHINE QuantifiedPredicate3

VARIABLES  x

INVARIANT  x : 0..5

INITIALISATION x := 1

OPERATIONS

	calculate = WHILE #p.(p:{z|z : 0..5 & z mod 2 = 0} & p < 5) DO x := x + 1 INVARIANT 1 = 1 VARIANT 10 -x END

END