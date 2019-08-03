MACHINE SetComprehension7

VARIABLES  set

INVARIANT  set : POW(INTEGER*INTEGER*INTEGER*INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x,y,z,a|x : 0..5 & y : 0..4 & z : 0..3 & a : 0..2} END;
	out <-- getRes = out := card(set)

END