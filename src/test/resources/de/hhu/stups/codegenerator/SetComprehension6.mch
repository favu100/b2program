MACHINE SetComprehension6

VARIABLES  set

INVARIANT  set : POW(INTEGER*INTEGER*INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x,y,z|x : 0..5 & y : 0..4 & z : 0..3} END;
	out <-- getRes = out := card(set)

END