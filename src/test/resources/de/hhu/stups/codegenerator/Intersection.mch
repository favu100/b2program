MACHINE Intersection

SETS EINT = {ONE, TWO, THREE, FOUR}

VARIABLES  x, y, z

INVARIANT  x <: EINT & y <: EINT & z <: EINT

INITIALISATION x := {ONE, TWO}; y := {TWO, THREE}; z := {}

OPERATIONS

	calculate = BEGIN z := x /\ y END;
	out <-- getRes = out := z

END