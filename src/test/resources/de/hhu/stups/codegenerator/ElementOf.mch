MACHINE ElementOf

VARIABLES  x, y, r

INVARIANT  x : POW(INT) & y : INT & r : BOOL

INITIALISATION x := {1,2}; y:= 1; r := TRUE

OPERATIONS

	calculate =
	    IF y : x THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END