MACHINE Plus

VARIABLES  x,y,res

INVARIANT  x : INT & y : INT & res : INT

INITIALISATION x := 1; y := 2; res := 0

OPERATIONS
	calculate = BEGIN res := x + y END;
	out <-- getRes = out := res

END