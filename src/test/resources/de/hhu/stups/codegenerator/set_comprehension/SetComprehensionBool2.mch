MACHINE SetComprehensionBool2

VARIABLES  x

INVARIANT  x : POW(BOOL*BOOL*BOOL*BOOL)

INITIALISATION x := {}

OPERATIONS

	calculate =
	    x:={a,b,c,d|(a=TRUE or b=TRUE) & (c=TRUE or d=TRUE)};

	out <-- getCard = out := card(x);
	
	out <-- getSet = out := x

END