MACHINE Nondeterminism10_MC

VARIABLES  x, y

INVARIANT  x : INTEGER & y : INTEGER

INITIALISATION x := 4 || y := 3

OPERATIONS

	calculate =
	BEGIN
	    x :: {1, 2, 3} ||
	    CHOICE
	        y :: 0..x
	    OR
	        y := 4
	    END
	END


END