MACHINE Fnc

VARIABLES  f, r

INVARIANT  f : INT <-> INT & r : INT +-> POW(INT)

INITIALISATION f := {1|->2, 1|->3, 1|->4, 2|->1}; r := {}

OPERATIONS

	calculate = BEGIN r := fnc(f) END;
	out <-- getRes = out := card(r)

END