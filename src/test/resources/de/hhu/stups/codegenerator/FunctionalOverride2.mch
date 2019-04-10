MACHINE FunctionalOverride2

VARIABLES  f, s

INVARIANT  f : INT --> INT & s : INT

INITIALISATION f := {0|->0, 1|->1, 2|->2}; s := 3

OPERATIONS

	calculate = BEGIN f(0) := 1; s := f(1) END;
	out <-- getRes = out := f(0)

END