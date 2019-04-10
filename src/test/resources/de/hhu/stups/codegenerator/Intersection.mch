MACHINE Intersection

VARIABLES  x, y, z

INVARIANT  x : POW(INT) & y : POW(INT) & z : POW(INT)

INITIALISATION x := {1,2}; y := {2,3}; z := {}

OPERATIONS

	calculate = BEGIN z := x /\ y END;
	out <-- getRes = out := z

END