MACHINE GeneralizedIntersectionEmpty

SETS EINT = {ONE, TWO, THREE, FOUR}

VARIABLES  set, x

INVARIANT  set : POW(POW(EINT)) & x : POW(EINT)

INITIALISATION set := {}; x := {}

OPERATIONS

	calculate = BEGIN x := inter(set); x := x \/ {ONE} END;
	out <-- getSet = out := set

END