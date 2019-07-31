MACHINE FunctionCallAccessNested

VARIABLES x, y, res

INVARIANT
	x : INTEGER +-> (INTEGER +-> INTEGER) &
	y : INTEGER &
	res : INTEGER

INITIALISATION
	x := {1|->{2|->3}, 2|->{3|->4}};
	y := 0;
	res := -1

OPERATIONS
	calculate = BEGIN
	    y := x(1)(2);
		x(1)(2) := 4;
		res := x(1)(2)
	END;

	out <-- getRes = BEGIN
	    out := res
	END

END