MACHINE GeneralizedUnionEmpty

VARIABLES  set, x

INVARIANT  set : POW(POW(INTEGER)) & x : POW(INTEGER)

INITIALISATION set := {}; x := {}

OPERATIONS

	calculate = BEGIN x := union(set); x := x \/ {1} END;
	out <-- getSet = out := set

END