MACHINE LetPredicate

VARIABLES  x

INVARIANT  x : BOOL

INITIALISATION x := FALSE

OPERATIONS

	calculate = IF LET a,b BE a = 1 & b = 2 IN a + b > 2 END THEN x:= TRUE END;

	out <-- getRes = out := x

END