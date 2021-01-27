MACHINE RelationGeneralizedUnionEmpty

VARIABLES  set, x

INVARIANT  set : POW(POW(INTEGER * INTEGER)) & x : POW(INTEGER * INTEGER)

INITIALISATION set := {}; x := {}

OPERATIONS

	calculate = BEGIN x := union(set); x := x \/ {1|->2} END;
	out <-- getSet = out := set

END