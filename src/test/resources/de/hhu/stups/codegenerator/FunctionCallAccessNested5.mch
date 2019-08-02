MACHINE FunctionCallAccessNested5

VARIABLES x, y, res

INVARIANT
	x : ((INTEGER * INTEGER) * INTEGER) +-> ((INTEGER * INTEGER) +-> INTEGER) &
	y : INTEGER &
	res : INTEGER

INITIALISATION
	x := {((1|->2)|->3)|->{(4|->5)|->6}};
	y := 0;
	res := -1

OPERATIONS
	calculate = BEGIN
	    y := x(1,2,3)(4,5);
		x(1,2,3)(4,5) := 8;
		res := x(1,2,3)(4,5)
	END;

	out <-- getRes = BEGIN
	    out := res
	END

END