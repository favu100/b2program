MACHINE Rel

VARIABLES  f, r

INVARIANT  f : INT +-> POW(INT) & r : INT <-> INT

INITIALISATION f := {1|->{2,3,4}, 2|->{1}}; r := {}

OPERATIONS

	calculate = BEGIN r := rel(f) END;
	out <-- getRes = out := card(r)

END