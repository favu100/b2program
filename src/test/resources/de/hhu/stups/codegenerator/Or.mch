MACHINE Or

VARIABLES  x, y, r

INVARIANT  x : BOOL & y : BOOL & r : BOOL

INITIALISATION x := TRUE; y := FALSE; r := FALSE

OPERATIONS

	calculate =
	    IF x = TRUE or y = TRUE THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END