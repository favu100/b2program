MACHINE And

VARIABLES  x, y, r

INVARIANT  x : BOOL & y : BOOL & r : BOOL

INITIALISATION x := TRUE; y := TRUE; r := FALSE

OPERATIONS

	calculate =
	    IF x = TRUE & y = TRUE THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END