MACHINE TupleProjection1

VARIABLES  f, x

INVARIANT  f : INT * INT & x : INT

INITIALISATION f := 1|->2; x := 0

OPERATIONS

	calculate = BEGIN x := prj1(INTEGER, INTEGER)(f) END;
	out <-- getRes = out := x;
	out <-- getPair = out := f

END