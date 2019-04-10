MACHINE Not

VARIABLES  x, r

INVARIANT  x : BOOL & r : BOOL

INITIALISATION x := TRUE; r := FALSE

OPERATIONS

	calculate =
	    IF not(x = TRUE) THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END