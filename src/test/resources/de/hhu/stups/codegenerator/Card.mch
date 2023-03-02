MACHINE Card

SETS X = {ONE, TWO}

VARIABLES  r

INVARIANT  r : INT

INITIALISATION r := 0

OPERATIONS

	calculate = BEGIN r := card(X) END;
	out <-- getRes = out := r

END