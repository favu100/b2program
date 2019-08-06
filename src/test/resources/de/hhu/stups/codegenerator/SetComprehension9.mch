MACHINE SetComprehension9

VARIABLES  set

INVARIANT  set : POW(INTEGER*INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x,y|x : 0..5 or y : 0..5 & x mod 2 = 1} END;
	out <-- getRes = out := card(set)

END