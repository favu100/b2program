MACHINE SetComprehension5

VARIABLES  set

INVARIANT  set : POW(INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x|x : 0..5 & x : {z | z : 0..x & z mod 3 = 0} & x mod 2 = 1} END;
	out <-- getRes = out := set

END