MACHINE Pred

VARIABLES  f, r

INVARIANT  f : INT & r : INT

INITIALISATION f := 1; r := 0

OPERATIONS

	calculate = BEGIN r := pred(f) END;
	out <-- getRes = out := r

END