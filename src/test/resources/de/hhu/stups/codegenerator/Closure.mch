MACHINE Closure

VARIABLES  f, s

INVARIANT  f : INT --> INT & s : INT --> INT

INITIALISATION f := {0|->1, 1|->2, 2|->3}; s := {}

OPERATIONS

	calculate = BEGIN s := closure(f) END;
	out <-- getRes = out := card(s)

END