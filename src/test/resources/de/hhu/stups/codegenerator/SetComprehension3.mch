MACHINE SetComprehension3

VARIABLES  set

INVARIANT  set : POW(INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x|x : {z | z : 0..6 & z mod 3 = 0} & x mod 2 = 1} END;
	out <-- getRes = out := set

END