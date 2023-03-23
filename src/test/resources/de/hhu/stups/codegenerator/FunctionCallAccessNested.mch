MACHINE FunctionCallAccessNested

SETS EINT = {ONE, TWO, FOUR}

VARIABLES x, y, res

INVARIANT
	x : EINT +-> (EINT +-> EINT) &
	y : EINT &
	res : EINT

INITIALISATION
	x := {ONE|->{TWO|->ONE}, TWO|->{FOUR|->ONE}};
	y := ONE;
	res := ONE

OPERATIONS
	calculate = BEGIN
	    y := x(ONE)(TWO);
		x(ONE)(TWO) := FOUR;
		res := x(ONE)(TWO)
	END;

	out <-- getRes = BEGIN
	    out := res
	END

END