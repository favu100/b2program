MACHINE RelationPow1

SETS EINT = {ONE, TWO, THREE}

VARIABLES  f, g

INVARIANT  f : POW(EINT * EINT) & g : POW(POW(EINT * EINT))

INITIALISATION f := {ONE|->TWO, TWO|-> THREE}; g := POW1(f)

OPERATIONS

	calculate = BEGIN g := g - {} END;
	out <-- getRes = out := card(g)

END