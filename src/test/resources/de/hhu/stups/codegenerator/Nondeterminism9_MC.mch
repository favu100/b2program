MACHINE Nondeterminism9_MC

VARIABLES  x, y

INVARIANT  x : INTEGER & y : INTEGER

INITIALISATION x := 4 || y := 3

OPERATIONS

	calculate =
	BEGIN
	    x :: {1, 2, 3} ||
	    IF x /= 2 THEN
	        y :: 0..x
	    ELSE
	        y := 4
	    END
	END


END