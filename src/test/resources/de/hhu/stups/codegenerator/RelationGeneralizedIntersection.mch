MACHINE RelationGeneralizedIntersection

VARIABLES  set, x

INVARIANT  set : POW(POW(INTEGER * INTEGER)) & x : POW(INTEGER * INTEGER)

INITIALISATION set := {{1|->2},{1|->2},{3|->4}}; x := {}

OPERATIONS

	calculate = BEGIN x := inter(set) END;
	out <-- getRes = out := x

END