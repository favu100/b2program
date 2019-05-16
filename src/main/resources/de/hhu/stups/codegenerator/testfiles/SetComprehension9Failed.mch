MACHINE SetComprehension9Failed

VARIABLES  set

INVARIANT  set : POW(INTEGER * INTEGER * INTEGER)

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := {x,y,z|x < 1 & y = 2 & z = 4 & (z > 0 or z < 5)} END

END