MACHINE SetComprehension11

VARIABLES  set

INVARIANT  set : POW(INTEGER*INTEGER*INTEGER)

INITIALISATION set := {}

OPERATIONS

	op = BEGIN set := {x,y,z|x : 0..5 & y : 0..4 & z : 0..3 & x < 3 & x = y} END;
	out <-- getRes = out := card(set)

END