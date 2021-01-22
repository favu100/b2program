MACHINE GeneralizedIntersection

VARIABLES  set, x

INVARIANT  set : POW(POW(INTEGER)) & x : POW(INTEGER)

INITIALISATION set := {{1},{2},{3}}; x := {}

OPERATIONS

	calculate = BEGIN x := inter(set) END;
	out <-- getRes = out := x

END