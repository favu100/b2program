MACHINE Multiply

VARIABLES  x,y,res

INVARIANT  x : INT & y : INT & res : INT

INITIALISATION x := 2; y := 2; res := 0

OPERATIONS
	calculate = BEGIN res := x*y END;
	out <-- getRes = out := res

END