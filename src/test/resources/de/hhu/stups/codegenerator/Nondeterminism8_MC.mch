MACHINE Nondeterminism8_MC

VARIABLES  x, y

INVARIANT  x : INTEGER & y : INTEGER

INITIALISATION x := 4 || y := 3

OPERATIONS

	calculate =
	BEGIN
	    x :: {0, 1} ||
	    ANY c WHERE
	        c : {1,2}
	    THEN
	        y := c
	    END
	END


END