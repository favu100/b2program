MACHINE SetComprehension_Pruning

VARIABLES  set

INVARIANT  set : POW(INTEGER*INTEGER)

INITIALISATION set := {}

OPERATIONS

	op = BEGIN set := {a,b|a : 1..10 & a mod 2 = 0 & b : 1..5} END

END