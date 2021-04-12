MACHINE SetComprehensionInteger3

VARIABLES  x

INVARIANT  x : POW(INTEGER)

INITIALISATION x := {}

OPERATIONS

	calculate =
	    x:={a|0<a & a<5};

	out <-- getCard = out := card(x);
	
	out <-- getSet = out := x

END