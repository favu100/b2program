MACHINE Inverse

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, r

INVARIANT  f : POW(EINT * EINT) & r : POW(EINT * EINT)

INITIALISATION f := {(ONE |-> TWO), (TWO |-> THREE), (THREE |-> FOUR), (FOUR |-> FIFE)}; r := {}

OPERATIONS

	calculate = BEGIN r := f~ END;
	out <-- getRes = out := card(r[{TWO, THREE, FOUR, FIFE}])

END