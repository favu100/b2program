MACHINE Lambda

VARIABLES  set

INVARIANT  set : 0..5 --> INTEGER

INITIALISATION set := {}

OPERATIONS

	calculate = BEGIN set := %p.(p:0..5 & p mod 2 = 0 | p * p) END;
	out <-- getRes = out := set(2)

END