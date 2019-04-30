MACHINE LetSubstitution

VARIABLES  x

INVARIANT  x : INTEGER

INITIALISATION x := 0

OPERATIONS

	calculate = x := LET a,b BE a = 1 & b = 2 IN x := a+b END

END