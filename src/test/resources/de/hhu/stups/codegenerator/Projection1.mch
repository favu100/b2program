MACHINE Projection1

VARIABLES  f, g, x

INVARIANT  f : INT * INT & g : POW(INT * INT * INT) & x : INT

INITIALISATION f := 1|->2; g := prj1({1,2,3},{2,3}); x := 0

OPERATIONS

	calculate = BEGIN x := g(f) END;
	out <-- getRes = out := x;
	out <-- getPair = out := f

END