MACHINE SetComprehension8

VARIABLES  set, xx

INVARIANT  set : POW(INTEGER*INTEGER) & xx : INTEGER

INITIALISATION set := {x,y|x : 1..2 & y : {1}}; xx := 3

OPERATIONS

	calculate = BEGIN set := {x,y|x : 0..5 & y : {xx}} || xx := set(1) END;
	out <-- getRes = out := xx

END