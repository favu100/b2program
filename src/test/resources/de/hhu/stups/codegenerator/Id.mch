MACHINE Id

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, r

INVARIANT  f : POW(EINT) & r : EINT --> EINT

INITIALISATION f := {ONE,TWO,THREE}; r := {}

OPERATIONS

	calculate = BEGIN IF id(f)[{TWO}] = {TWO} THEN r := id(f) ELSE r := {} END END;
	out <-- getRes = out := card(r)

END