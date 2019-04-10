MACHINE FunctionalOverride

VARIABLES  f, s

INVARIANT  f : INT --> INT & s : INT

INITIALISATION f := {0|->0, 1|->1, 2|->2}; s := 3

OPERATIONS

	calculate = BEGIN s := f(1) END;
	out <-- getRes = out := s

END