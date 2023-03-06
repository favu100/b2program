MACHINE Composition

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, s, r

INVARIANT  f : EINT --> EINT & s : EINT --> EINT & r : EINT --> EINT

INITIALISATION f := {ZERO|->ZERO, ONE|->ONE, TWO|->TWO}; s := {ONE|->THREE}; r:= {}

OPERATIONS

	calculate = BEGIN r := (f;s) END;
	out <-- getRes = out := card(r)

END