MACHINE Iterate

VARIABLES  f, s

INVARIANT  f : INT --> INT & s : INT --> INT

INITIALISATION f := {0|->1, 1|->2, 2|->3}; s := {}

OPERATIONS

	calculate = BEGIN s := iterate(f,5) END;
	out <-- getRes = out := card(s)

END