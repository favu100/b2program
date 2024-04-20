MACHINE SetComprehension12

VARIABLES  set

INVARIANT  set : POW(INTEGER*INTEGER*INTEGER)

INITIALISATION set := {}

OPERATIONS

	op = BEGIN set := {x,y,z|x : 0..5 & x < 3 & y : 0..4 & x = y & z : 0..3 & x > -1} END;
	out <-- getRes = out := card(set)

END