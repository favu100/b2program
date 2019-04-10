MACHINE Subset

VARIABLES  x, y, r

INVARIANT  x : POW(INT) & y : POW(INT) & r : BOOL

INITIALISATION x := {1,2}; y:= {1,2,3}; r := TRUE

OPERATIONS

	calculate =
	    IF x <: y THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END