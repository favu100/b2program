MACHINE Pow1

VARIABLES  f, r

INVARIANT  f : POW(INT) & r : POW(POW(INT))

INITIALISATION f := {1,2,3}; r := {}

OPERATIONS

	calculate = BEGIN r := POW1(f) END;
	out <-- getRes = out := card(r)

END