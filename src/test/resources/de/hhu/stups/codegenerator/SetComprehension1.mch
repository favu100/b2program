MACHINE SetComprehension1

VARIABLES  set

INVARIANT  set : POW(INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x|x : 0..5 & x mod 2 = 1} END;
	out <-- getRes = out := card(set)

END