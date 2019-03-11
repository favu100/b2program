MACHINE Projections

VARIABLES  f

INVARIANT  f : INT * INT & x : INT

INITIALISATION f := 1|->2; x := prj1(f)

OPERATIONS

	calculate = BEGIN x := prj2(f) END

END