MACHINE GreaterEqual

VARIABLES  x, y, r

INVARIANT  x : INT & y : INT & r : BOOL

INITIALISATION x := 1; y := 2; r := FALSE

OPERATIONS

	calculate =
	    IF x >= y THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END