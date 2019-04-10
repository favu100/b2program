MACHINE Closure1

VARIABLES  f, s

INVARIANT  f : INT --> INT & s : INT --> INT

INITIALISATION f := {0|->1, 1|->2, 2|->3}; s := {}

OPERATIONS

	calculate = BEGIN s := closure1(f) END;
	out <-- getRes = out := card(s)

END