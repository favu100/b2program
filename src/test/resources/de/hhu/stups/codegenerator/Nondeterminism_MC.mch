MACHINE Nondeterminism_MC

VARIABLES  x, y

INVARIANT  x : INTEGER & y : INTEGER

INITIALISATION x := 4 || y := 3

OPERATIONS

	calculate =
    ANY a,b WHERE
        a : {4,5} &
        b : {5,6} &
        y < 1000
    THEN
        y := a + b
    END


END