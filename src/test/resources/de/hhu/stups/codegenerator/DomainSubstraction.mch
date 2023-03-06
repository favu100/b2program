MACHINE DomainSubstraction

SETS EINT = {ZERO, ONE, TWO, THREE, FOUR, FIFE, SIX}

VARIABLES  f, g, r

INVARIANT  f : POW(EINT * EINT) & g : POW(EINT) & r : POW(EINT*EINT)

INITIALISATION f := {(ONE |-> TWO), (TWO |-> THREE), (THREE |-> FOUR), (FOUR |-> FIFE), (FIFE |-> SIX)}; g := {ONE,TWO}; r := {}

OPERATIONS

	calculate = BEGIN r := g <<| f END;
	out <-- getRes = out := card(r)

END