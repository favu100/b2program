MACHINE NotElementOf

SETS EINT = {ONE, TWO, THREE}

VARIABLES  x, y, r

INVARIANT  x <: EINT & y : EINT & r : BOOL

INITIALISATION x := {ONE, TWO}; y:= ONE; r := FALSE

OPERATIONS

	calculate =
	    IF y /: x THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END