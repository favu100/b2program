MACHINE Nondeterminism4_MC

VARIABLES  x, y

INVARIANT  x : INTEGER & y : INTEGER

INITIALISATION x := 4 || y := 3

OPERATIONS

	calculate =
	x :: 1..2 ||
    ANY a,b WHERE
        a : {0,1} &
        b : {1} &
        y < 1000
    THEN
        y := a + b
    END


END