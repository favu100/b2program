MACHINE TestMachine

VARIABLES x, y

INVARIANT x : INTEGER & y : INTEGER

INITIALISATION x := 6; y := 0

OPERATIONS
	op = BEGIN
             ANY p
	     WHERE p = x & p : 0..5 THEN
	     	x := x - p
             END;
	     y := 15
	     END


END