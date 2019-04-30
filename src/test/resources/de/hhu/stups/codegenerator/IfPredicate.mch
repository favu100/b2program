MACHINE IfPredicate

VARIABLES  x,y

INVARIANT  x : INTEGER & y : BOOL

INITIALISATION x := 1 || y := FALSE

OPERATIONS

	calculate = IF IF x > 0 THEN 1=2 ELSE 1=1 END THEN y := TRUE END;

	out <-- getRes = out := y

END