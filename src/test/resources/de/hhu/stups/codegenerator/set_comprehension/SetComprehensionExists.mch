MACHINE SetComprehensionExists

VARIABLES  x

INVARIANT  x : POW(INTEGER*INTEGER)

INITIALISATION x := {}

OPERATIONS

	calculate =
	    x:={a,b|a:1..100 & b:1..100 & 3<a & b<10 & ∃c.(c:1..100 & a<c & c<b)};

	out <-- getCard = out := card(x);
	
	out <-- getSet = out := x

END