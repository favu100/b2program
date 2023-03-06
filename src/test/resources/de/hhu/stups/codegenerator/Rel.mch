MACHINE Rel

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, r

INVARIANT  f : EINT +-> POW(EINT) & r : EINT <-> EINT

INITIALISATION f := {ONE|->{TWO,THREE,FOUR}, TWO|->{ONE}}; r := {}

OPERATIONS

	calculate = BEGIN r := rel(f) END;
	out <-- getRes = out := card(r)

END