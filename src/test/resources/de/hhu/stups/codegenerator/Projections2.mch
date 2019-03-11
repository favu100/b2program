MACHINE Projections2

VARIABLES  x

INVARIANT  x : (INT * INT) --> INT

INITIALISATION x := prj1(1..3,1..3)

OPERATIONS

	calculate = BEGIN x := prj1(1..3,1..3) END

END