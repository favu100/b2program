MACHINE GeneralizedUnion

SETS EINT = {ONE, TWO, THREE, FOUR}

VARIABLES  set, x

INVARIANT  set : POW(POW(EINT)) & x : POW(EINT)

INITIALISATION set := {{ONE},{TWO},{THREE}}; x := {}

OPERATIONS

	calculate = BEGIN x := union(set) END;
	out <-- getRes = out := x

END