MACHINE Range

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, r

INVARIANT  f : POW(EINT * EINT) & r : POW(EINT)

INITIALISATION f := {(ONE |-> TWO), (TWO |-> THREE), (THREE |-> FOUR), (FOUR |-> FIFE)}; r := {}

OPERATIONS

	calculate = BEGIN r := ran(f) END;
	out <-- getRes = out := card(r)

END