MACHINE FunctionCallAccessNested2

VARIABLES x, y, res

INVARIANT
	x : INTEGER +-> (INTEGER +-> (INTEGER +-> INTEGER)) &
	y : INTEGER &
	res : INTEGER

INITIALISATION
	x := {1|->{2|->{3|->4}}, 2|->{3|->{4|->5}}};
	y := 0;
	res := -1

OPERATIONS
	calculate = BEGIN
	    y := x(1)(2)(3);
		x(1)(2)(3) := 5;
		res := x(1)(2)(3)
	END;

	out <-- getRes = BEGIN
	    out := res
	END

END