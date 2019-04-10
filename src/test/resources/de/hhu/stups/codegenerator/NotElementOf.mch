MACHINE NotElementOf

VARIABLES  x, y, r

INVARIANT  x : POW(INT) & y : INT & r : BOOL

INITIALISATION x := {1,2}; y:= 1; r := FALSE

OPERATIONS

	calculate =
	    IF y /: x THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END