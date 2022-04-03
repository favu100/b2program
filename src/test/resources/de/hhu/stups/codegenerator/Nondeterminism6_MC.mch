MACHINE Nondeterminism6_MC

VARIABLES  x, y, z, c

INVARIANT  x : INTEGER & y : INTEGER & z : INTEGER & c : INTEGER

INITIALISATION x := 4 || y := 3 || z := 0 || c := 4

OPERATIONS

	calculate =

    CHOICE z := min({x, y})
        OR z := max({x, y})
        OR z := 1
        OR z := 2
        OR
        ANY a,b WHERE
           a : {0,1} &
           b : {1} &
           y < 1000
        THEN
           y := a + b ||
           x :: 1..2 ||
           c :: 1..x
        END
    END



END