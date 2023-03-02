MACHINE NotStrictSubset

SETS EINT = {ONE, TWO, THREE, FOUR}

VARIABLES  x, y, r

INVARIANT  x <: EINT & y <: EINT & r : BOOL

INITIALISATION x := {ONE, TWO}; y:= {ONE, TWO, THREE}; r := FALSE

OPERATIONS

	calculate =
	    IF x /<<: y THEN
	        r := TRUE
	    END;
	out <-- getRes = out := r

END