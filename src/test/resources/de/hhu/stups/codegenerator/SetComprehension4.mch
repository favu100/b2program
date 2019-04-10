MACHINE SetComprehension4

VARIABLES  set

INVARIANT  set : POW(INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x|x : {z | z : {y | y : 0..10 & y mod 4 = 0} & z mod 3 = 0} & x mod 2 = 1} END;
	out <-- getRes = out := set

END