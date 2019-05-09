MACHINE RelationPow

VARIABLES  f, g

INVARIANT  f : POW(INT * INT) & g : POW(POW(INT * INT))

INITIALISATION f := {1|->2, 2|-> 3}; g := POW(f)

OPERATIONS

	calculate = BEGIN g := g - {} END;
	out <-- getRes = out := card(g)

END