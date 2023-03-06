MACHINE Fnc

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, r

INVARIANT  f : EINT <-> EINT & r : EINT +-> POW(EINT)

INITIALISATION f := {ONE|->TWO, ONE|->THREE, ONE|->FOUR, TWO|->ONE}; r := {}

OPERATIONS

	calculate = BEGIN r := fnc(f) END;
	out <-- getRes = out := card(r)

END