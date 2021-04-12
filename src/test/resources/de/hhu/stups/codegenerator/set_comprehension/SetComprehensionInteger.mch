MACHINE SetComprehensionInteger

VARIABLES  x

INVARIANT  x : POW(INTEGER*INTEGER)

INITIALISATION x := {}

OPERATIONS

	calculate =
	    x:={a,b|a>3 & a<6 & b=a};

	out <-- getCard = out := card(x);
	
	out <-- getSet = out := x

END