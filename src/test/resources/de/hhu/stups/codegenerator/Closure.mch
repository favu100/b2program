MACHINE Closure

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, s

INVARIANT  f : EINT --> EINT & s : EINT --> EINT

INITIALISATION f := {ZERO|->ONE, ONE|->TWO, TWO|->THREE}; s := {}

OPERATIONS

	calculate = BEGIN s := closure(f) END;
	out <-- getRes = out := card(s)

END