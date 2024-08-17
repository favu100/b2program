MACHINE SetComprehension_Old

VARIABLES  set

INVARIANT  set : POW(INTEGER*INTEGER)

INITIALISATION set := {}

OPERATIONS

	op = BEGIN set := {a,b|a : 1..10 & b : 1..5 & a mod 2 = 0} END

END