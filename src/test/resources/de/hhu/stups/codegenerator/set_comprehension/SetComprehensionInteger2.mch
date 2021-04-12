MACHINE SetComprehensionInteger2

VARIABLES  x

INVARIANT  x : POW(INTEGER*INTEGER*INTEGER)

INITIALISATION x := {}

OPERATIONS

	calculate =
	    x:={a, b, c|a:3..6 & b: 3..6 & c=1 & a>3 & a<6 & b=a};

	out <-- getCard = out := card(x);
	
	out <-- getSet = out := x

END