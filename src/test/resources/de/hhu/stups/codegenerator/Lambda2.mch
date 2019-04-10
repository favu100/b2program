MACHINE Lambda2

VARIABLES  set

INVARIANT  set : 0..5 --> INTEGER

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := %p.(p:{x|x : 0..5 & x mod 2 = 0} & p mod 2 = 0 | p * p) END;
	out <-- getRes = out := set(2)

END