MACHINE Iterate

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, s

INVARIANT  f : EINT --> EINT & s : EINT --> EINT

INITIALISATION f := {ZERO|->ONE, ONE|->TWO, TWO|->THREE}; s := {}

OPERATIONS

	calculate = BEGIN s := iterate(f,5) END;
	out <-- getRes = out := card(s)

END