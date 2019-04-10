MACHINE Fin

VARIABLES  f, r

INVARIANT  f : POW(INT) & r : POW(POW(INT))

INITIALISATION f := {1,2,3}; r := {}

OPERATIONS

	calculate = BEGIN r := FIN(f) END;
	out <-- getRes = out := card(r)

END