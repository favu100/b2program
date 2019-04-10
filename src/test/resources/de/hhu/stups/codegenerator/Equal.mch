MACHINE Equal

VARIABLES  x, y, r

INVARIANT  x : BOOL & y : BOOL & r : BOOL

INITIALISATION x := TRUE; y := TRUE; r := FALSE

OPERATIONS

	calculate =
	    IF x = y THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END