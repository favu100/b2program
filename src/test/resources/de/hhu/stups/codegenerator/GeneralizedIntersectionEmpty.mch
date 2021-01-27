MACHINE GeneralizedIntersectionEmpty

VARIABLES  set, x

INVARIANT  set : POW(POW(INTEGER)) & x : POW(INTEGER)

INITIALISATION set := {}; x := {}

OPERATIONS

	calculate = BEGIN x := inter(set); x := x \/ {1} END;
	out <-- getSet = out := set

END