MACHINE SetComprehensionBool

VARIABLES  x

INVARIANT  x : POW(BOOL*BOOL)

INITIALISATION x := {}

OPERATIONS

	calculate =
	    x:={a,b|a=TRUE or b=TRUE};

	out <-- getCard = out := card(x);
	
	out <-- getSet = out := x

END