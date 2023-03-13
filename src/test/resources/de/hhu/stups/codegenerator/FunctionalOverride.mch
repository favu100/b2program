MACHINE FunctionalOverride

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR}

VARIABLES  f, s

INVARIANT  f : EINT --> EINT & s : EINT

INITIALISATION f := {ZERO|->ZERO, ONE|->ONE, TWO|->TWO}; s := THREE

OPERATIONS

	calculate = BEGIN s := f(ONE) END;
	out <-- getRes = IF s = ONE THEN out := 1 ELSE out := 0 END

END