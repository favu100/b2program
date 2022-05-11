MACHINE Nondeterminism3_MC

VARIABLES  x, y

INVARIANT  x : INTEGER & y : INTEGER

INITIALISATION x := 4 || y := 3

OPERATIONS

	calculate = y :: 1..x+1


END